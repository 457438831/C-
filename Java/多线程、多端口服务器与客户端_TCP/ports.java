package test;

public class ports {
	byte[] portPool;
	int myPort;
	static int lineNumber = 0;
	public ports(byte[] p) {
		this.portPool = p;
	}
	
	public synchronized int findPort() {
		//查询空闲端口
		
		for(myPort = 0;myPort<portPool.length;myPort++)
		{
			//如果端口被使用值为一
			if(portPool[myPort]==0)
			{
				portPool[myPort] = 1;
				
				System.out.print("链接数量[" + (++lineNumber) +"/"+ portPool.length + "]");
				return myPort;
			}
		}
		
		return myPort = -1;
	}
	
	public synchronized void freePort() {
		if(myPort != -1) {
			portPool[myPort] = 0;
			System.out.print("链接数量[" + (--lineNumber) +"/"+ portPool.length + "]");
		}
	}

}
