package test;


/**
 * 将byte数组转换成字符串
 * byte数组默认初始化为0  返回0之前的值
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
