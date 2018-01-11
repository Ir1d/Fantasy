import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class DBSCAN {
 private int dimension;// 数据维度
 private double eps = 0.5;
 private int threshold = 15;
 private double distance[][];
 private Map<Integer, Integer> id = new HashMap<Integer, Integer>();
 private int countClusters = 0;
 private ArrayList<Integer> keyPointList = new ArrayList<Integer>();//
 private int[] flags;// 标记边缘点

 private class Edge {
 int p, q;
 double weight;
 }

 private class Node {
 double[] attributes;

 public Node() {
 attributes = new double[8680];
 }
 }

 private ArrayList<Node> nodeList;
 private ArrayList<Edge> edgeList;

 private double getDistance(Node one, Node two) {// 计算两点间的欧氏距离
  double val = 0;
  double a = 0, b = 0;
  for (int i = 0; i < dimension; ++i) {
    val += one.attributes[i] * two.attributes[i];
    a += one.attributes[i] * one.attributes[i];
    b += two.attributes[i] * two.attributes[i];
  }
  return val / (sqrt(a) * sqrt(b));
 // double val = 0;
 // for (int i = 0; i < dimension; ++i) {
 // val += (one.attributes[i] - two.attributes[i]) * (one.attributes[i] - two.attributes[i]);
 // }
 // return Math.sqrt(val);
 }

 public void loadEdges() {// 给所有在扫描半径内的核心点之间加边，标记边界点并且自动忽略噪声点
 edgeList = new ArrayList<Edge>();
 flags = new int[nodeList.size()];
 int[] countPoint = new int[nodeList.size()];
 for (int i = 0; i < countPoint.length; ++i) {
 countPoint[i] = 1;// 每一个点一开始都是核心点
 }
 for (int i = 0; i < nodeList.size(); ++i) {
 for (int j = i + 1; j < nodeList.size(); ++j) {
 distance[i][j] = getDistance(nodeList.get(i), nodeList.get(j));
  out.println(distance[i][j]);
 if (distance[i][j] <= eps) {// 两点间距离小于扫描半径
 countPoint[i]++;
 if (countPoint[i] > 0 && countPoint[i] < threshold) {
 flags[i] = j;// 记录边界点
 }
 if (countPoint[i] >= threshold) {// 如果记录当前点的扫描半径内密度值大于或等于给定阈值
 flags[i] = 0;
 if (!keyPointList.contains(i)) {
 keyPointList.add(i);
 }
 }
 countPoint[j]++;
 if (countPoint[j] > 0 && countPoint[j] < threshold) {
 flags[j] = i;// 记录边界点
 }
 if (countPoint[j] >= threshold) {// 如果记录当前点的扫描半径内密度值大于或等于给定阈值
 flags[j] = 0;
 if (!keyPointList.contains(j)) {
 keyPointList.add(j);
 }
 }
 }
 }
 }

 for (int i = 0; i < keyPointList.size(); ++i) {
 for (int j = i + 1; j < keyPointList.size(); ++j) {
 Edge edge = new Edge();
 edge.p = keyPointList.get(i);
 edge.q = keyPointList.get(j);
 edge.weight = distance[edge.p][edge.q];

 if (edge.weight <= eps) {
 if (!id.containsKey(edge.p)) {// 为后期使用并查集求连通分量做准备
 id.put(edge.p, edge.p);
 }
 if (!id.containsKey(edge.q)) {
 id.put(edge.q, edge.q);
 }
 edgeList.add(edge);
 }
 }
 }

 }

 public void setInput(String path) {
 try {
 BufferedReader br = new BufferedReader(new FileReader(path));
 String str;
 String[] strArray;
 nodeList = new ArrayList<Node>();
 while ((str = br.readLine()) != null) {
 strArray = str.split(",");
 dimension = strArray.length;
 Node node = new Node();
 for (int i = 0; i < dimension; ++i) {
 node.attributes[i] = Double.parseDouble(strArray[i]);
 }
 nodeList.add(node);
 }
 distance = new double[nodeList.size()][nodeList.size()];
 loadEdges();
 br.close();
 } catch (IOException e) {
 e.printStackTrace();
 }
 }

 public void union(int p, int q) {// 并操作
 int a = find(p);
 int b = find(q);
 if (a != b) {
 id.put(a, b);
 }
 }

 public int find(int p) {// 查操作
 if (p != id.get(p)) {
 id.put(p, find(id.get(p)));
 }
 return id.get(p);
 }

 public void processDBSCAN(String path) {
 try {
 PrintStream out = new PrintStream(path);
 out.println("核心点为： " + keyPointList);
 out.println();
 for (int i = 0; i < edgeList.size(); ++i) {
 out.println("核心点 (" + edgeList.get(i).p + " " +
                              edgeList.get(i).q + ") 之间的距离为: " + edgeList.get(i).weight);
 }
 for (int i = 0; i < edgeList.size(); ++i) {
 union(edgeList.get(i).p, edgeList.get(i).q);// 利用并查集将点集变为连通分量
 }

 Iterator<Integer> it = id.keySet().iterator();
 while (it.hasNext()) {
 int key = it.next();
 if (id.get(key) == key) {// 利用并查集得到强连通分量个数
 ++countClusters;
 }
 }
 out.println();
 for (int i = 0; i < flags.length; ++i) {
 if (flags[i] != 0) {
 out.println("点" + i + "属于点" + flags[i] + "所在的簇");
 }
 }
 out.println();
 out.println("由核心点连通分量数量得知共有: " + countClusters + "个簇");
 out.close();
 System.out.println("Please check results in: " + path);
 } catch (Exception e) {
 e.printStackTrace();
 }
 }

 public void printOutput(String path) {
 processDBSCAN(path);
 }

 public static void main(String[] args) {
 DBSCAN dbscan = new DBSCAN();
 dbscan.setInput("a.in");
 dbscan.printOutput("a.out");
 }
}