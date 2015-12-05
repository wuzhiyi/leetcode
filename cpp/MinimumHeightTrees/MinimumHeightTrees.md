###Minimum Height Trees
URL: https://leetcode.com/problems/minimum-height-trees/</br>
For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains `n` nodes which are labeled from `0` to `n - 1`. You will be given the number `n` and a list of undirected `edges` (each edge is a pair of labels).

You can assume that no duplicate edges will appear in `edges`. Since all edges are undirected, `[0, 1]` is the same as `[1, 0]` and thus will not appear together in `edges`.

####Example 1:

Given `n = 4`, `edges = [[1, 0], [1, 2], [1, 3]]`

        0
        |
        1
       / \
      2   3

return `[1]`

####Example 2:

Given `n = 6`, `edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]`

     0  1  2
      \ | /
        3
        |
        4
        |
        5

return `[3, 4]`

####Hint:

How many MHTs can a graph have at most?

####Note:

1. According to the [definition of tree on Wikipedia](https://en.wikipedia.org/wiki/Tree_(graph_theory)): “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
2. The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

__Code:__

	class Solution {
	public:
	    struct TreeNode{
	        set<int> list;//使用set结构方便删除邻居
	        TreeNode(){};
	        bool isLeaf(){ return list.size() == 1; };//如果是叶子节点，那么邻居大小是1
	    };
	    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
	 
	        if (n == 1) return{ 0 };//当n为1时，初始化node1为空，下面的程序执行结果会输出空
	 
	        vector<TreeNode> tree(n);
	        for (auto e : edges)
	        {//使用节点来存储这棵树，耗费的空间为O(n+2e)
	            tree[e.first].list.insert(e.second);
	            tree[e.second].list.insert(e.first);
	        }
	 
	        vector<int> node1(0);//记录当前的叶子节点
	        vector<int> node2(0);//记录删除node1叶子节点后，成为新的叶子节点的节点
	 
	        for (int i = 0; i < tree.size();i++)
	        {//记录叶子节点
	            if (tree[i].isLeaf())
	                node1.push_back(i);
	        }
	         
	        while (1)
	        {
	            for (auto leaf:node1)
	            {
	                //使用迭代器遍历邻居
	                for (set<int>::iterator ite = tree[leaf].list.begin(); ite != tree[leaf].list.end(); ite++)
	                {
	                    int neighbor = *ite;
	                    tree[neighbor].list.erase(leaf);//删除叶子节点
	                    if (tree[neighbor].isLeaf())//删除后，如果是叶子节点，则放到node2中
	                        node2.push_back(neighbor);
	                }
	            }
	            if (node2.empty())
	            {//遍历完后，如果node2为空，即node1中的节点不是叶子节点，要么是剩下一个节点，要么剩下两个相互连接的节点
	                break;
	            }
	            node1.clear();
	            swap(node1, node2);
	        }
	        if (node1.size() != 0)
	            return node1;//node1中只剩下1个节点，因为邻居为空，所以不能压进node2中
	        else if (node1.size() == 0)
	            return node2;//node1中有两个节点，且互相连接，邻居都为1，所以被压进node2中(此时邻居都被清除),然后在下一轮循环，两者都不被视为叶子节点
	    }
	};