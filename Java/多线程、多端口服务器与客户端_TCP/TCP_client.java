package test;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

import java.util.Scanner;

public class TCP_client {

	public static String SERVER_ADDRESS = "119.23.63.81";
	public static void main(String[] str) throws IOException
	{
		System.out.println("�ͻ�������----");
		Socket socket = new Socket(SERVER_ADDRESS,9559);                    //����TCP socket����
		 
		InputStream inputStream = socket.getInputStream();
		System.out.println("��ȡ�¶˿�----");
		byte newPort = (byte) inputStream.read();
		socket.close();
		if(newPort==-1)
		{	System.out.println("û�ж���Ķ˿�������---");
			return;
		}
		System.out.println("�¶˿�:"+ (9560 + newPort)+"----");
			
		socket = new Socket(SERVER_ADDRESS,(9560 + newPort));
		OutputStream outputStream = socket.getOutputStream();	         //����socket�������������  

		Scanner scanner = new Scanner(System.in);						 //������������
		
		
		while(true) {
			System.out.print("���������ݣ�");
			String string = scanner.nextLine();
			outputStream.write(string.getBytes());					 //������д����
			if("quit".equals(string))
				break;
		}
		System.out.print("���������ͷ���Դ");
		scanner.close();
		outputStream.close();
		socket.close();
	}
	
}
