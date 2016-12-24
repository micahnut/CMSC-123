import java.io.*;
import java.util.*;

public class FileDescriptor {
	String content;
	String filename;
	boolean isDIR;
	// String fileType;
	Date dateCreated;
	Date dateModified;

	FileDescriptor() {
		content = "";
		filename = "root";
		// fileType = "";
		isDIR = true;

		this.dateCreated = new Date();
	}

	FileDescriptor(String filename, boolean isDIR) {
		this.filename = filename;
		this.isDIR = isDIR;
		this.dateCreated = new Date();
		setDate();

	}

	public void setDate() {
		this.dateModified = new Date();
	}

	void appendContent(String newContent) {
		content = content + newContent;
	}

	public String getFilename() {
		return filename;
	}

	public void setFilename(String filename) {
		this.filename = filename;
	}

	public String getContent() {
		return content;
	}

	public boolean isDIR() {
		return isDIR;
	}

	void display() {
		System.out.println("Name : " + filename);
		System.out.println("File type: ");
		if (isDIR) {
			System.out.println("Folder");
		} else {
			System.out.println("Text file");
		}

	}

}
