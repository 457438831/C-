package test;

public class ports {
	byte[] portPool;
	int myPort;
	static int lineNumber = 0;
	public ports(byte[] p) {
		this.portPool = p;
	}
	
	public synchronized int findPort() {
		//��ѯ���ж˿�
		
		for(myPort = 0;myPort<portPool.length;myPort++)
		{
			//����˿ڱ�ʹ��ֵΪһ
			if(portPool[myPort]==0)
			{
				portPool[myPort] = 1;
				
				System.out.print("��������[" + (++lineNumber) +"/"+ portPool.length + "]");
				return myPort;
			}
		}
		
		return myPort = -1;
	}
	
	public synchronized void freePort() {
		if(myPort != -1) {
			portPool[myPort] = 0;
			System.out.print("��������[" + (--lineNumber) +"/"+ portPool.length + "]");
		}
	}

}
