
/**
* 数据结构--图
* 内容：图的两种存储方式(邻接矩阵、邻接表)，两种存储方式的遍历(深度优先、广度优先)，图的应用(最小生成树、最短路径)
* 
* 时间：2022/10/10
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define weight_type int		//弧的权重类型

// 邻接矩阵
typedef struct Graph_Struct{
	char* vertex;			//存储顶点
	weight_type* link;		//存储关系
	int max = 0;			//顶点数    防止越界访问
}Graph_Struct,* Graph_point;

//迪杰斯特拉算法结构体
typedef struct Vertex_Struct {
	int parent;
	int index;
	weight_type weight;
}Vertex_Struct,* Vertex_point;

Graph_Struct graph;

/**
* 创建邻接矩阵
* vertex:传入要创建的顶点数组
* vertex_count:顶点数量
* return:成功返回1，失败返回0
*/
int createGraph(char* vertexs,int vertex_count) {
	if (vertexs == NULL || vertex_count == 0)
		return NULL;

	weight_type* dLink = (weight_type*)calloc(vertex_count * vertex_count,sizeof(weight_type));//创建矩阵 calloc会将内存清零
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
* 添加顶点关系
* from:弧尾   传入顶点在数组的下标
* target:弧头
* weight:弧的权重，默认为1
* return:成功返回1，失败返回0
*/
int addLink(int from,int target,weight_type weight = 1) {
	if (graph.max == 0)
		return 0;
	else if (from >= graph.max || target >= graph.max || from == target)//不能越界，不能自己到自己
		return 0;
	graph.link[(from * graph.max) + target] = weight;					//没有用数组形式，所以手动跨界
	return 1;
}


/**
* 释放内存
*/
void freeGraph() {
	free(graph.link);
	graph.link = NULL;
	free(graph.vertex);
	graph.vertex = NULL;
}

/**
* 最小生成树 
* prim算法
*/
void showGraph_minTree_prim() {
	if (graph.link == NULL || graph.max == 0)
		return;
	//申请堆区空间
	char* temp_vertex = (char*)calloc(graph.max,sizeof(char));										//临时数组顶点
	weight_type* temp_weight = (weight_type*)calloc(graph.max, sizeof(weight_type));				//临时数组权重
	if (temp_vertex == NULL || temp_weight == NULL)
		return;
	
	int vertex_index = 0;																			//用于标记顶点数组下标
	int weight_index = 0;																			//用于标记权重数组下标
	weight_type temp_v;
	while (true) {
		//拷贝最小权值和顶点
		temp_v = graph.link[(graph.max * vertex_index) + weight_index];
		if (temp_v > 0 && (temp_weight[weight_index] > 0 ? temp_v < temp_weight[weight_index] : true))//权值小的留下 并且将当前顶点也保存到临时数组
		{
			temp_weight[weight_index] = temp_v;														 //临时数组权值
			temp_vertex[weight_index] = vertex_index;												//临时数组顶点
		}

		if (weight_index < graph.max - 1)															//遍历到末尾 会停在最后一个顶点的下标
			++weight_index;
		else {
			//修改自身权值，移动到下一个顶点
			temp_weight[vertex_index] = -1;															//将自己到自己的权值修改为-1
			for (int i = 0; i < graph.max; i++) 
				if (temp_weight[i] > 0 && (temp_weight[weight_index] > 0 ? temp_weight[i] < temp_weight[weight_index] : true))
					weight_index = i;																//存储最小权值的下标

			if (temp_weight[weight_index] <= 0)														//如果最小权值小于等于0 代表末尾
				break;
			printf("%c → %c 权值:%d\n",graph.vertex[temp_vertex[weight_index]],graph.vertex[weight_index],temp_weight[weight_index]);
			vertex_index = weight_index;															//通过最小权值的下标找到对应顶点
			weight_index = 0;
		}
	}
	//释放空间，因为方法结束即将弹栈，所以不赋空值
	free(temp_vertex);
	free(temp_weight);
}

/**
* 输出最短路径
* from:出发顶点的下标
* to:目的地的下标
*/
void showShort_path(int from,int to) {
	if (from == to || from < 0 || from >= graph.max || to < 0 || to >= graph.max)
		return;
	//初始化
	Vertex_point* vertexArr = (Vertex_point*)calloc(graph.max, sizeof(Vertex_point));//创建指针数组 用于存放顶点
	char* flag = (char*)calloc(graph.max,sizeof(char));								 //创建一个标志数组，用于记录数据使用情况
	Vertex_point frist_vertex = (Vertex_point)calloc(1,sizeof(Vertex_Struct));		 //出发顶点
	if (vertexArr == NULL || flag == NULL || frist_vertex == NULL)
		return;
	frist_vertex->parent = -1;
	frist_vertex->index = from;
	frist_vertex->weight = 0;
	vertexArr[0] = frist_vertex;
	flag[from] = -1;
	
	//开始查找
	int arr_index = 0;
	int find_index = 0;
	int min_weight = 0;
	int now_weight = 0;
	Vertex_point arr_vertex = NULL;
	while (true) {
		now_weight = graph.link[(graph.max * vertexArr[arr_index]->index) + find_index];//从顶点关系中取出权值
		now_weight == 0 ? true: now_weight = now_weight + vertexArr[arr_index]->weight;//计算路径总权值
		if (now_weight > 0 && flag[find_index] != -1&&								   //有效数据且没有被标记
			(min_weight == 0 ? min_weight = now_weight :							   //第一次直接赋值到最小权值
				(min_weight > now_weight ? min_weight = now_weight : false)))		   //保留最小权值
		{//创建、更新顶点数据
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
				if (arr_vertex == NULL || arr_index >= graph.max)						//走到末尾或没有新节点 则表明没有路径
				{
					printf("从%c到%c没有路径", graph.vertex[from], graph.vertex[to]);
					break;
				}
				else if (arr_vertex->index == to) {										//找到数据 输出信息
					frist_vertex = arr_vertex;											//记录当前指针，输出结束后释放
					printf("权值:%d 路径:", arr_vertex->weight);
					while (true)
					{
						printf("%c", graph.vertex[arr_vertex->index]);
						if (arr_vertex->parent == -1) {
							printf("\n");
							break;
						}
						printf("←");
						arr_vertex = vertexArr[arr_vertex->parent];
					}
					free(frist_vertex);
					break;
				}
				//将顶点结构插入顶点数组中，初始化数据并修改标志位
				vertexArr[arr_index] = arr_vertex;										//将创建的节点插入顶点数组中
				flag[arr_vertex->index] = -1;											//将对应标记位修改
				arr_index = 0;
				min_weight = 0;
				arr_vertex = NULL;
			}
			find_index = 0;
		}
	}

	//释放内存
	for (int i = 0; i < arr_index; i++)
	{
		arr_vertex = vertexArr[i];
		free(arr_vertex);
	}
	free(flag);
	free(vertexArr);
}

/**
* 拓扑排序
*/
void topoSort(int start) {
	int* comeIn = (int*)malloc(sizeof(int) * graph.max);
	if (comeIn == NULL || start < 0 || start >= graph.max)
		return;
	//统计所有顶点的入度
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
	if (comeIn[start] != 0 ? printf("顶点%c的入度不为零", graph.vertex[start]) : false)
		return;
	int hasWeight = 0;//标记是否有没有使用的顶点
	while (true) {
		//输出顶点并修改标记位
		printf("%c",graph.vertex[start]);
		comeIn[start] = -1;
		//删除出度
		for (int rank = 0; rank < graph.max; rank++)
			if (graph.link[(graph.max * start) + rank] > 0)
				comeIn[rank] = comeIn[rank] - 1;
		//查找下一个入度为零的顶点
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
		printf("→");
	}
	if (hasWeight == 1) 
		printf("拓扑排序失败");
	free(comeIn);
}


/*测试案例
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
	//创建图
	#define number 7
	char in[number];						//录入顶点
	int f = 0, t = 0, w = 0;
	for (size_t i = 0; i < number; i++)
	{
		in[i] = getc(stdin);
	}
	createGraph(in, number);
	//插入边
	while (true) {					//录入边(弧) 输入下标
		scanf_s("%d %d %d",&f,&t,&w);
		if (f == t)					//输入相同顶点结束输入
			break;
		addLink(f,t,w);
	}
	showGraph_minTree_prim();		//输出最小生成树
	//最短路径
	//int a, b;
	//while (true) {					//输入起点 终点的下标

	//	scanf_s("%d %d", &a, &b);
	//	if (a == b)
	//		break;
	//	showShort_path(a, b);
	//}
	//拓扑排序
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