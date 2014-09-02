import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class Main
{
	public static void main(String[] args)
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i=0;
		try{
            i = Integer.parseInt(br.readLine());
        }catch(NumberFormatException nfe){
            System.err.println("Invalid Format!");
        }catch(IOException e){}
		for(int q=0;q<i;q++)
			runTest();
	}
	public static void runTest(){
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i=0;
		try{
            i = Integer.parseInt(br.readLine());
        }catch(NumberFormatException nfe){
            System.err.println("Invalid Format!");
        }catch(IOException e){
			
		}
		System.out.println(i+1);
	}
}
