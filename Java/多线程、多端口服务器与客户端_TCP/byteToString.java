package test;


/**
 * ��byte����ת�����ַ���
 * byte����Ĭ�ϳ�ʼ��Ϊ0  ����0֮ǰ��ֵ
 * */
public class byteToString {
	
	public String to(byte[] bte)
	{
		int length = 0;
		for(byte b:bte)
		{
			if(b==0)
				break;
			length++;
		}
		return new String(bte,0,length);
	}
	
	public void clear(byte[] bte) {
		for(int i = 0;i < bte.length;i++) {
			if(bte[i] == 0)
				return;
			bte[i] = 0;
		}
	}

}
