package il.co.ilrd.crud;

import java.io.IOException;
import java.io.Serializable;
import java.util.Observable;
import java.util.Observer;

public class FileObserver implements Observer{

	public FileCrud fileCrud;
	
	public FileObserver(String pathToFile) throws IOException {
		fileCrud = new FileCrud(pathToFile);
	}
	
	@Override
	public void update(Observable o, Object obj) {
			fileCrud.create((String)obj);		
	}

}
