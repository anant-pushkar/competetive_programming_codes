#include"symboltable.h"
//Create a new hashtable of given size
hashtable_t *ht_create( int size ) {
	hashtable_t *hashtable = NULL;
	int i;
	if( size < 1 ) return NULL;
	if( ( hashtable = malloc( sizeof( hashtable_t ) ) ) == NULL ) {
		return NULL;
	}
	/* Allocate pointers to the head nodes. */
	if( ( hashtable->table = malloc( sizeof( entry_t * ) * size ) ) == NULL ) {
		return NULL;
	}
	for( i = 0; i < size; i++ ) {
		hashtable->table[i] = NULL;
	}
	hashtable->size = size;
	return hashtable;
}
hashtable_t *create_from_file(FILE *fptr)
{
	int size;
	fscanf(fptr,"%d",&size);
	hashtable_t *ht = ht_create( size );
	
	char key[20],val[10];
	while(!feof(fptr)){
		fscanf(fptr,"%s %s",key,val);
		//fscanf(fptr,"%s",val);
		ht_set( ht, key, val);
	}
	return ht;
}
//dump symbol table to temporary file
void print_table(hashtable_t *hashtable,FILE *fptr)
{
	int i;
	fprintf(fptr,"%d\n",hashtable->size);
	for(i=0;i<hashtable->size;i++){
		entry_t *pair = hashtable->table[i];
		while( pair != NULL && pair->key != NULL ) {
			fprintf(fptr,"%s %s\n",pair->key,pair->value);
			pair = pair->next;
		}
	}
}

/* Hash a string for a particular hash table. */
int ht_hash( hashtable_t *hashtable, char *key ) {

	unsigned long int hashval=1;
	int i = 0;
	/* Convert our string to an integer */
	while( hashval < ULONG_MAX && i < strlen( key ) ) {
		hashval = hashval << 8;
		hashval += key[ i ];
		i++;
	}
	return hashval % hashtable->size;
}
/* Create a key-value pair. */
entry_t *ht_newpair( char *key, char *value ) {
	entry_t *newpair;
	if( (newpair = malloc( sizeof( entry_t )) ) == NULL ) return NULL;
	if( (newpair->key = strdup( key )) == NULL ) return NULL;
	if( (newpair->value = strdup( value )) == NULL ) return NULL;
	newpair->next = NULL;
	return newpair;
}

/* Insert a key-value pair into a hash table. */
void ht_set( hashtable_t *hashtable, char *key, char *value ) {
	int bin = 0;
	entry_t *newpair = NULL;
	entry_t *next = NULL;
	entry_t *last = NULL;
	bin = ht_hash( hashtable, key );
	next = hashtable->table[ bin ];
	while( next != NULL && next->key != NULL && strcmp( key, next->key ) > 0 ) {
		last = next;
		next = next->next;
	}
	/* if there's already a pair , replace that string. */
	if( next != NULL && next->key != NULL && strcmp( key, next->key ) == 0 ) {
		free( next->value );
		next->value = strdup( value );
	/* else insert new entry*/
	} else {
		newpair = ht_newpair( key, value );
		/* if start of the linked list in this bin. */
		if( next == hashtable->table[ bin ] ) {
			newpair->next = next;
			hashtable->table[ bin ] = newpair;
		/* if end of the linked list in this bin. */
		} else if ( next == NULL ) {
			last->next = newpair;
		/* if middle of the list. */
		} else  {
			newpair->next = next;
			last->next = newpair;
		}
	}
}
/* Retrieve a key-value pair from a hash table. */
char *ht_get( hashtable_t *hashtable, char *key ) {
	int bin = 0;
	entry_t *pair;

	bin = ht_hash( hashtable, key );

	/* Step through the bin, looking for value. */
	pair = hashtable->table[ bin ];
	while( pair != NULL && pair->key != NULL && strcmp( key, pair->key ) > 0 ) {
		pair = pair->next;
	}
	/* If key does not exist */
	if( pair == NULL || pair->key == NULL || strcmp( key, pair->key ) != 0 ) return NULL;
	else return pair->value;
}


