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
		System.out.println("客户端启动----");
		Socket socket = new Socket(SERVER_ADDRESS,9559);                    //创建TCP socket链接
		 
		InputStream inputStream = socket.getInputStream();
		System.out.println("获取新端口----");
		byte newPort = (byte) inputStream.read();
		socket.close();
		if(newPort==-1)
		{	System.out.println("没有多余的端口链接了---");
			return;
		}
		System.out.println("新端口:"+ (9560 + newPort)+"----");
			
		socket = new Socket(SERVER_ADDRESS,(9560 + newPort));
		OutputStream outputStream = socket.getOutputStream();	         //根据socket创建输入输出流  

		Scanner scanner = new Scanner(System.in);						 //键盘输入数据
		
		
		while(true) {
			System.out.print("请输入数据：");
			String string = scanner.nextLine();
			outputStream.write(string.getBytes());					 //向流中写数据
			if("quit".equals(string))
				break;
		}
		System.out.print("结束程序释放资源");
		scanner.close();
		outputStream.close();
		socket.close();
	}
	
}
