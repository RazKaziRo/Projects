package il.co.ilrd.buffer_sort;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class FileToArrayHelper {
	
	CountingHelper bf = new CountingHelper();
	ArrayList<String> result = new ArrayList<String>();
	
	public ArrayList<String> getResult(String filePath) throws FileNotFoundException, IOException{
		
		try (FileReader f = new FileReader(filePath)) {
		    StringBuffer sb = new StringBuffer();
		    while (f.ready()) {
		        char c = (char) f.read();
		        if (c == '\n') {
		            result.add(sb.toString());
		            sb = new StringBuffer();
		        } else {
		            sb.append(c);
		        }
		    }
		    if (sb.length() > 0) {
		        result.add(sb.toString());
		    }
		}
		
		return result;
	}

	
}
