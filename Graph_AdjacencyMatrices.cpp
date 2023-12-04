/*ͼ�Ĵ洢��ʽ�����ڽӾ���*/
#include <iostream>
using namespace std;
/*typedef char VertexType;
�����ͣ�typedef��char�����Զ���Ϊ VertexType����VertexType������char�ͣ� VertexType a ���൱�� char a��*/
typedef char VertexType;             //��������Ӧ���û�����

#define MAXVEX  20             //��󶥵�����Ӧ���û�����
struct Graph {
	VertexType vexs[MAXVEX];            //�����
	int   arc[MAXVEX][MAXVEX];         //�ڽӾ��󣬴洢��
	int numVertexes, numEdges;      //ͼ�е�ǰ�Ķ������ͱ���
};
//��λ������±�
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
//����һ��������ͼ���ڽӾ����ʾ
void CreateGraph(Graph& g) {
	int i, j, k, w;
	cout << "���붥�����ͱ���:" << endl;
	cin >> g.numVertexes >> g.numEdges;//ȫ�ֱ�������������

	cout << "�����붥���������Ϣ��ÿ�������õ�����ĸ��ʾ�����Իس���������" << endl;
	for (i = 0; i < g.numVertexes; i++) 
	{
		cin >> g.vexs[i];//���붥��
	}
	cout << "������Ķ����ǣ�";
	for (i = 0; i < g.numVertexes; i++)
	{
		cout << g.vexs[i];
	}
	cout << endl;
	for (i = 0; i < g.numVertexes; i++)
	{
		for (j = 0; j < g.numVertexes; j++) {
			g.arc[i][j] = 0; //�ڽӾ����ʼ��Ϊÿ����ԪΪ��
		}
	}
	cout << "�����(vi,vj)�ϵĶ���i���ƣ�����j���ƺ�Ȩֵ��ÿ����������Իؼ�����" << endl;
	for (k = 0; k < g.numEdges; k++) {
		char p, q;
		cin >> p >> q;//��������������������������
		cin >> w;//����ߵ�Ȩֵ
		int m = -1;
		int n = -1;
		m = locates(g, p);//��������Ϊp�Ķ�����±�
		n = locates(g, q);//��������Ϊq�Ķ�����±�
		if (m == -1 || n == -1) {
			cout << "there is no vertex." << endl; //��ʾ�����д���Ϣ
			return;
		}
		//��Ϊ������ͼ������Գ�
		g.arc[m][n] = w;
		g.arc[n][m] = w; 
	}
}
//��ӡͼ
void printGraph(Graph g) {
	int i, j;
	cout << "����ڽӾ���Ϊ��" << endl;
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
	CreateGraph(g); //�ڽӾ��󴴽�ͼ
	printGraph(g); //��ӡ�ڽӾ���
	system("pause");
	return 0;
}
