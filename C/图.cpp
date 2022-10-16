
/**
* ���ݽṹ--ͼ
* ���ݣ�ͼ�����ִ洢��ʽ(�ڽӾ����ڽӱ�)�����ִ洢��ʽ�ı���(������ȡ��������)��ͼ��Ӧ��(��С�����������·��)
* 
* ʱ�䣺2022/10/10
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define weight_type int		//����Ȩ������

// �ڽӾ���
typedef struct Graph_Struct{
	char* vertex;			//�洢����
	weight_type* link;		//�洢��ϵ
	int max = 0;			//������    ��ֹԽ�����
}Graph_Struct,* Graph_point;

//�Ͻ�˹�����㷨�ṹ��
typedef struct Vertex_Struct {
	int parent;
	int index;
	weight_type weight;
}Vertex_Struct,* Vertex_point;

Graph_Struct graph;

/**
* �����ڽӾ���
* vertex:����Ҫ�����Ķ�������
* vertex_count:��������
* return:�ɹ�����1��ʧ�ܷ���0
*/
int createGraph(char* vertexs,int vertex_count) {
	if (vertexs == NULL || vertex_count == 0)
		return NULL;

	weight_type* dLink = (weight_type*)calloc(vertex_count * vertex_count,sizeof(weight_type));//�������� calloc�Ὣ�ڴ�����
	char* dVertex = (char*)calloc(vertex_count,1);
	if (dLink == NULL || dVertex == NULL)
		return NULL;

	memcpy(dVertex,vertexs,vertex_count);
	
	graph.vertex = dVertex;
	graph.link = dLink;
	graph.max = vertex_count;
	return 1;
}

/**
* ��Ӷ����ϵ
* from:��β   ���붥����������±�
* target:��ͷ
* weight:����Ȩ�أ�Ĭ��Ϊ1
* return:�ɹ�����1��ʧ�ܷ���0
*/
int addLink(int from,int target,weight_type weight = 1) {
	if (graph.max == 0)
		return 0;
	else if (from >= graph.max || target >= graph.max || from == target)//����Խ�磬�����Լ����Լ�
		return 0;
	graph.link[(from * graph.max) + target] = weight;					//û����������ʽ�������ֶ����
	return 1;
}


/**
* �ͷ��ڴ�
*/
void freeGraph() {
	free(graph.link);
	graph.link = NULL;
	free(graph.vertex);
	graph.vertex = NULL;
}

/**
* ��С������ 
* prim�㷨
*/
void showGraph_minTree_prim() {
	if (graph.link == NULL || graph.max == 0)
		return;
	//��������ռ�
	char* temp_vertex = (char*)calloc(graph.max,sizeof(char));										//��ʱ���鶥��
	weight_type* temp_weight = (weight_type*)calloc(graph.max, sizeof(weight_type));				//��ʱ����Ȩ��
	if (temp_vertex == NULL || temp_weight == NULL)
		return;
	
	int vertex_index = 0;																			//���ڱ�Ƕ��������±�
	int weight_index = 0;																			//���ڱ��Ȩ�������±�
	weight_type temp_v;
	while (true) {
		//������СȨֵ�Ͷ���
		temp_v = graph.link[(graph.max * vertex_index) + weight_index];
		if (temp_v > 0 && (temp_weight[weight_index] > 0 ? temp_v < temp_weight[weight_index] : true))//ȨֵС������ ���ҽ���ǰ����Ҳ���浽��ʱ����
		{
			temp_weight[weight_index] = temp_v;														 //��ʱ����Ȩֵ
			temp_vertex[weight_index] = vertex_index;												//��ʱ���鶥��
		}

		if (weight_index < graph.max - 1)															//������ĩβ ��ͣ�����һ��������±�
			++weight_index;
		else {
			//�޸�����Ȩֵ���ƶ�����һ������
			temp_weight[vertex_index] = -1;															//���Լ����Լ���Ȩֵ�޸�Ϊ-1
			for (int i = 0; i < graph.max; i++) 
				if (temp_weight[i] > 0 && (temp_weight[weight_index] > 0 ? temp_weight[i] < temp_weight[weight_index] : true))
					weight_index = i;																//�洢��СȨֵ���±�

			if (temp_weight[weight_index] <= 0)														//�����СȨֵС�ڵ���0 ����ĩβ
				break;
			printf("%c �� %c Ȩֵ:%d\n",graph.vertex[temp_vertex[weight_index]],graph.vertex[weight_index],temp_weight[weight_index]);
			vertex_index = weight_index;															//ͨ����СȨֵ���±��ҵ���Ӧ����
			weight_index = 0;
		}
	}
	//�ͷſռ䣬��Ϊ��������������ջ�����Բ�����ֵ
	free(temp_vertex);
	free(temp_weight);
}

/**
* ������·��
* from:����������±�
* to:Ŀ�ĵص��±�
*/
void showShort_path(int from,int to) {
	if (from == to || from < 0 || from >= graph.max || to < 0 || to >= graph.max)
		return;
	//��ʼ��
	Vertex_point* vertexArr = (Vertex_point*)calloc(graph.max, sizeof(Vertex_point));//����ָ������ ���ڴ�Ŷ���
	char* flag = (char*)calloc(graph.max,sizeof(char));								 //����һ����־���飬���ڼ�¼����ʹ�����
	Vertex_point frist_vertex = (Vertex_point)calloc(1,sizeof(Vertex_Struct));		 //��������
	if (vertexArr == NULL || flag == NULL || frist_vertex == NULL)
		return;
	frist_vertex->parent = -1;
	frist_vertex->index = from;
	frist_vertex->weight = 0;
	vertexArr[0] = frist_vertex;
	flag[from] = -1;
	
	//��ʼ����
	int arr_index = 0;
	int find_index = 0;
	int min_weight = 0;
	int now_weight = 0;
	Vertex_point arr_vertex = NULL;
	while (true) {
		now_weight = graph.link[(graph.max * vertexArr[arr_index]->index) + find_index];//�Ӷ����ϵ��ȡ��Ȩֵ
		now_weight == 0 ? true: now_weight = now_weight + vertexArr[arr_index]->weight;//����·����Ȩֵ
		if (now_weight > 0 && flag[find_index] != -1&&								   //��Ч������û�б����
			(min_weight == 0 ? min_weight = now_weight :							   //��һ��ֱ�Ӹ�ֵ����СȨֵ
				(min_weight > now_weight ? min_weight = now_weight : false)))		   //������СȨֵ
		{//���������¶�������
			if (arr_vertex == NULL) {
				arr_vertex = (Vertex_point)malloc(sizeof(Vertex_Struct));
				if (arr_vertex == NULL)return;
			}	
			arr_vertex->index = find_index;
			arr_vertex->weight = min_weight;
			arr_vertex->parent = arr_index;	
		}

		if (find_index < graph.max - 1)
			++find_index;
		else {
			++arr_index;
			if (arr_index >= graph.max || vertexArr[arr_index] == NULL)
			{
				if (arr_vertex == NULL || arr_index >= graph.max)						//�ߵ�ĩβ��û���½ڵ� �����û��·��
				{
					printf("��%c��%cû��·��", graph.vertex[from], graph.vertex[to]);
					break;
				}
				else if (arr_vertex->index == to) {										//�ҵ����� �����Ϣ
					frist_vertex = arr_vertex;											//��¼��ǰָ�룬����������ͷ�
					printf("Ȩֵ:%d ·��:", arr_vertex->weight);
					while (true)
					{
						printf("%c", graph.vertex[arr_vertex->index]);
						if (arr_vertex->parent == -1) {
							printf("\n");
							break;
						}
						printf("��");
						arr_vertex = vertexArr[arr_vertex->parent];
					}
					free(frist_vertex);
					break;
				}
				//������ṹ���붥�������У���ʼ�����ݲ��޸ı�־λ
				vertexArr[arr_index] = arr_vertex;										//�������Ľڵ���붥��������
				flag[arr_vertex->index] = -1;											//����Ӧ���λ�޸�
				arr_index = 0;
				min_weight = 0;
				arr_vertex = NULL;
			}
			find_index = 0;
		}
	}

	//�ͷ��ڴ�
	for (int i = 0; i < arr_index; i++)
	{
		arr_vertex = vertexArr[i];
		free(arr_vertex);
	}
	free(flag);
	free(vertexArr);
}

/**
* ��������
*/
void topoSort(int start) {
	int* comeIn = (int*)malloc(sizeof(int) * graph.max);
	if (comeIn == NULL || start < 0 || start >= graph.max)
		return;
	//ͳ�����ж�������
	for (int rank = 0; rank < graph.max; rank++)
	{
		int sun = 0;
		for (int row = 0; row < graph.max; row++)
		{
			if (graph.link[(graph.max * row) + rank] > 0)
				++sun;
		}
		comeIn[rank] = sun;
		sun = 0;
	}
	if (comeIn[start] != 0 ? printf("����%c����Ȳ�Ϊ��", graph.vertex[start]) : false)
		return;
	int hasWeight = 0;//����Ƿ���û��ʹ�õĶ���
	while (true) {
		//������㲢�޸ı��λ
		printf("%c",graph.vertex[start]);
		comeIn[start] = -1;
		//ɾ������
		for (int rank = 0; rank < graph.max; rank++)
			if (graph.link[(graph.max * start) + rank] > 0)
				comeIn[rank] = comeIn[rank] - 1;
		//������һ�����Ϊ��Ķ���
		start = -1;
		hasWeight = 0;
		for (int newVertex = 0; newVertex < graph.max; newVertex++)
		{
			if (comeIn[newVertex] == 0)
			{
				start = newVertex;
				hasWeight = 1;
				break;
			}
			else if (comeIn[newVertex] > 0) {
				hasWeight = 1;
			}
		}
		if (start == -1)
			break;
		printf("��");
	}
	if (hasWeight == 1) 
		printf("��������ʧ��");
	free(comeIn);
}


/*���԰���
ABCDEF
0 1 6
0 2 1
0 3 5
1 4 3
2 1 5
2 4 6
2 5 4
2 3 5
5 4 6
5 3 2
1 1 0
*/
int main(int argc, char* argv)
{
	//����ͼ
	#define number 7
	char in[number];						//¼�붥��
	int f = 0, t = 0, w = 0;
	for (size_t i = 0; i < number; i++)
	{
		in[i] = getc(stdin);
	}
	createGraph(in, number);
	//�����
	while (true) {					//¼���(��) �����±�
		scanf_s("%d %d %d",&f,&t,&w);
		if (f == t)					//������ͬ�����������
			break;
		addLink(f,t,w);
	}
	showGraph_minTree_prim();		//�����С������
	//���·��
	//int a, b;
	//while (true) {					//������� �յ���±�

	//	scanf_s("%d %d", &a, &b);
	//	if (a == b)
	//		break;
	//	showShort_path(a, b);
	//}
	//��������
	int fg = 0;
	while (true)
	{
		scanf_s("%d", &fg);
		if (fg == 99)
			break;
		topoSort(fg);
	}
	
	 
	freeGraph();
	return 0;
}