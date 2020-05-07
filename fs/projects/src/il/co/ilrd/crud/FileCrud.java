package il.co.ilrd.crud;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Serializable;

public class FileCrud implements Crud<String, Integer>{
	
	Integer lineNumber = 0;
	BufferedWriter bufferWriter;
	
	public FileCrud(String txtFilePath) throws IOException {
		bufferWriter = new BufferedWriter(new FileWriter(txtFilePath, true));
	}

	@Override
	public void close() throws Exception {
		bufferWriter.close();
	}

	@Override
	public Integer create(String lineToWrite) {
		
		if(lineToWrite != null) {
			try {
				System.out.println("Writing Line: " + lineToWrite);
				bufferWriter.append(lineToWrite);
				bufferWriter.newLine();
				bufferWriter.flush();
			} 
			catch (IOException e) {
			e.printStackTrace();
			}
		
		++lineNumber;
		}
		
		else {
			try {
				close();
			} 	
			catch (Exception e) {
				e.printStackTrace();
			}
		}
		
		return lineNumber;
	}

	@Override
	public String read(Integer key) {
		throw new UnsupportedOperationException();
	}

	@Override
	public void update(Integer key, String obj) {
		throw new UnsupportedOperationException();		
	}

	@Override
	public String delete(Integer key) {
		throw new UnsupportedOperationException();
	}
}
