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
		System.out.println("服务器启动----");
		ServerSocket server = new ServerSocket(9559);         //创建服务器监听socket
		TCP_server tcp_server = new TCP_server();
		while(true) {
			System.out.println("主线程等待链接----");
			//接受到socket数据
			Socket socket = server.accept();                        //接受数据
			//创建新的服务器监听端口，重新链接客户端
			System.out.println("主线程接受到新TCP链接----");
			tcp_server.createNewLink(socket);
			
			
			
		}
		
	}
	
	private void createNewLink(Socket socket) {
		new Thread() {
			@Override
			public void run() {
				
					System.out.println("新线程创建----");
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
					{	System.out.println("端口分配失败----");
						return;}
					System.out.println("新端口创建----");
					ServerSocket server = new ServerSocket(9560 + myPort);
					Socket so = server.accept();
					InputStream in = so.getInputStream();
					byte[] data = new byte[1024];
					byteToString byteToString = new byteToString();
					while(true) {
						
						System.out.println((9560+myPort)+ ":监听数据----" +so.isConnected());
						
						
						in.read(data);
						System.out.println("接受到来自" +so.getInetAddress()+"："+
								so.getPort() +": " + byteToString.to(data) +" 本地IP："+ so.getLocalAddress() +"  本地端口:" + so.getLocalPort());
						if(byteToString.to(data).equals("quit")) {
							in.close();
							so.close();
							server.close();
							System.out.println("quit 关闭流----");
							break;
						}
						byteToString.clear(data);
						
					}
					System.out.println("正常释放端口："+ myPort +"----");
					ps.freePort();
					
										
				} catch (IOException e) {
				
					e.printStackTrace();
					System.out.println("异常释放端口："+ myPort +"----");
					ps.freePort();
				}
		
			}
		}.start();
	
	}

}
