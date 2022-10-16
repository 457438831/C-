package test;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Scanner;

public class UDP_client {

	
	public static void main(String[] str) {
		
		Scanner scanner = new Scanner(System.in);
		
		
		try {
			//�����׽���
			DatagramSocket socket = new DatagramSocket();
			while(true) {
			String string = scanner.nextLine();
			//�������ݰ�
			DatagramPacket packet = new DatagramPacket(string.getBytes(),string.length(),InetAddress.getByName("127.0.0.1"),9559);
			//����
			socket.send(packet);
			if("quit".equals(string))
				break;
			}
			socket.close();
			
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
}
