/*图的存储方式——邻接矩阵*/
#include <iostream>
using namespace std;
/*typedef char VertexType;
语句解释：typedef将char类型自定义为 VertexType，即VertexType代表了char型， VertexType a 就相当于 char a；*/
typedef char VertexType;             //顶点类型应由用户定义

#define MAXVEX  20             //最大顶点数，应由用户定义
struct Graph {
	VertexType vexs[MAXVEX];            //顶点表
	int   arc[MAXVEX][MAXVEX];         //邻接矩阵，存储边
	int numVertexes, numEdges;      //图中当前的顶点数和边数
};
//定位顶点的下标
int locates(Graph& g, char ch) {
	int i = 0;
	for (i = 0; i < g.numVertexes; i++) {
		if (g.vexs[i] == ch) {
			break;
		}
	}
	if (i >= g.numVertexes) {
		return -1;
	}
	return i;
}
//建立一个无向网图的邻接矩阵表示
void CreateGraph(Graph& g) {
	int i, j, k, w;
	cout << "输入顶点数和边数:" << endl;
	cin >> g.numVertexes >> g.numEdges;//全局变量方便后面操作

	cout << "请输入顶点的数据信息，每个顶点用单个字母表示，并以回车键结束：" << endl;
	for (i = 0; i < g.numVertexes; i++) 
	{
		cin >> g.vexs[i];//输入顶点
	}
	cout << "你输入的顶点是：";
	for (i = 0; i < g.numVertexes; i++)
	{
		cout << g.vexs[i];
	}
	cout << endl;
	for (i = 0; i < g.numVertexes; i++)
	{
		for (j = 0; j < g.numVertexes; j++) {
			g.arc[i][j] = 0; //邻接矩阵初始化为每个单元为零
		}
	}
	cout << "输入边(vi,vj)上的顶点i名称，顶点j名称和权值，每个边输入后以回键结束" << endl;
	for (k = 0; k < g.numEdges; k++) {
		char p, q;
		cin >> p >> q;//输入边所依附的两个顶点的名称
		cin >> w;//输入边的权值
		int m = -1;
		int n = -1;
		m = locates(g, p);//查找名称为p的顶点的下标
		n = locates(g, q);//查找名称为q的顶点的下标
		if (m == -1 || n == -1) {
			cout << "there is no vertex." << endl; //显示输入有错信息
			return;
		}
		//因为是无向图，矩阵对称
		g.arc[m][n] = w;
		g.arc[n][m] = w; 
	}
}
//打印图
void printGraph(Graph g) {
	int i, j;
	cout << "这个邻接矩阵为：" << endl;
	for (i = 0; i < g.numVertexes; i++) {
		for (j = 0; j < g.numVertexes; j++) {
			cout << "     " << g.arc[i][j];
		}
		cout << endl;
	}
}
int main() 
{
	Graph g;
	CreateGraph(g); //邻接矩阵创建图
	printGraph(g); //打印邻接矩阵
	system("pause");
	return 0;
}
