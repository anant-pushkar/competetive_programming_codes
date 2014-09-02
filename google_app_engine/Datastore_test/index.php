<?php
/*
Project Name : Datastore_test
Created on   : Sun Aug  3 15:06:54 2014
test project to test datastore integration
*/
// Get a handle on the datastore itself
$factory   = new Java('com.google.appengine.api.datastore.DatastoreServiceFactory');
$datastore = $factory->getDatastoreService();

// Lookup data by known key name
$key_factory= new Java('com.google.appengine.api.datastore.KeyFactory');
$userEntity = $datastore->get($key_factory->createKey("UserInfo", $_GET["key"]));

?>
