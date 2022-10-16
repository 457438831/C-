package test;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;


public class UDP_server {

	
	public static void main(String[] str) throws IOException {
		
		
			//创建套接字监听端口
			DatagramSocket socket = new DatagramSocket(9559);
			//创建数据包缓存区
			DatagramPacket packet = new DatagramPacket(new byte[1024], 1024);
		while(true) {
			//监听数据
			socket.receive(packet);
			//获取数据和长度
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
