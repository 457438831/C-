package test;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;


public class TCP_server {
	static byte[]  JWWPORTS= new byte[2];
	public static void main(String[] str) throws IOException
	{
		System.out.println("����������----");
		ServerSocket server = new ServerSocket(9559);         //��������������socket
		TCP_server tcp_server = new TCP_server();
		while(true) {
			System.out.println("���̵߳ȴ�����----");
			//���ܵ�socket����
			Socket socket = server.accept();                        //��������
			//�����µķ����������˿ڣ��������ӿͻ���
			System.out.println("���߳̽��ܵ���TCP����----");
			tcp_server.createNewLink(socket);
			
			
			
		}
		
	}
	
	private void createNewLink(Socket socket) {
		new Thread() {
			@Override
			public void run() {
				
					System.out.println("���̴߳���----");
					ports ps = new ports(JWWPORTS);						
					int myPort = ps.findPort();
				try {OutputStream pOutputStream = socket.getOutputStream();
					pOutputStream.write(myPort);
					try {
						sleep(2000);
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
					pOutputStream.close();
					socket.close();
					if(myPort == -1)
					{	System.out.println("�˿ڷ���ʧ��----");
						return;}
					System.out.println("�¶˿ڴ���----");
					ServerSocket server = new ServerSocket(9560 + myPort);
					Socket so = server.accept();
					InputStream in = so.getInputStream();
					byte[] data = new byte[1024];
					byteToString byteToString = new byteToString();
					while(true) {
						
						System.out.println((9560+myPort)+ ":��������----" +so.isConnected());
						
						
						in.read(data);
						System.out.println("���ܵ�����" +so.getInetAddress()+"��"+
								so.getPort() +": " + byteToString.to(data) +" ����IP��"+ so.getLocalAddress() +"  ���ض˿�:" + so.getLocalPort());
						if(byteToString.to(data).equals("quit")) {
							in.close();
							so.close();
							server.close();
							System.out.println("quit �ر���----");
							break;
						}
						byteToString.clear(data);
						
					}
					System.out.println("�����ͷŶ˿ڣ�"+ myPort +"----");
					ps.freePort();
					
										
				} catch (IOException e) {
				
					e.printStackTrace();
					System.out.println("�쳣�ͷŶ˿ڣ�"+ myPort +"----");
					ps.freePort();
				}
		
			}
		}.start();
	
	}

}
