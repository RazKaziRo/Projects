package il.co.ilrd.crud;

import java.io.IOException;
import java.io.Serializable;
import java.util.Observable;
import java.util.Observer;

public class FileObserver implements Observer{

	public CrudFile crudFile;
	
	public FileObserver(String pathToFile) throws IOException {
		crudFile = new CrudFile(pathToFile);
	}
	
	@Override
	public void update(Observable o, Object obj) {
		crudFile.create((String)obj);		
	}
	
	public void close() throws Exception {
		crudFile.close();
	}	

}
