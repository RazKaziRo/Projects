package il.co.ilrd.networking;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;

public class NetworkingEx {
	
    public static void DownloadWebPage(String webpage) 
    { 
        try { 
  
            URL url = new URL(webpage); 
            BufferedReader readr =  
              new BufferedReader(new InputStreamReader(url.openStream())); 
  
            BufferedWriter writer =  
              new BufferedWriter(new FileWriter("/home/student/Desktop/download.html")); 
              
            String line; 
            while ((line = readr.readLine()) != null) { 
                writer.write(line); 
            } 
  
            readr.close(); 
            writer.close(); 
            System.out.println("Successfully Downloaded."); 
        } 
  
        catch (MalformedURLException mue) { 
            System.out.println("Malformed URL Exception raised"); 
        } 
        catch (IOException ie) { 
            System.out.println("IOException raised"); 
        } 
    } 
    
    public static void main(String [] args) {
    	
    	String url = "https://www.razk.sg-host.com/"; 
        DownloadWebPage(url); 
    }
} 

