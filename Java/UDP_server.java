package test;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;


public class UDP_server {

	
	public static void main(String[] str) throws IOException {
		
		
			//�����׽��ּ����˿�
			DatagramSocket socket = new DatagramSocket(9559);
			//�������ݰ�������
			DatagramPacket packet = new DatagramPacket(new byte[1024], 1024);
		while(true) {
			//��������
			socket.receive(packet);
			//��ȡ���ݺͳ���
			byte[] data = packet.getData();
			int length = packet.getLength();
			String string = new String(data,0,length);
			System.out.println(string);
			
			if("quit".equals(string))
				{socket.close();
				return;}
		}
	
	
	
}
}
