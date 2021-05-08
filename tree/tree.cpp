#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
// 遍历的意思: https://www.pianshen.com/article/7106254596/
// 二叉树结点
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;

	TreeNode(int x): val(x), left(NULL), right(NULL), parent(NULL){}
};

/* 二叉树的遍历 */
class TreeOrder {
public:
	// 前序遍历(递归法)
	void pre_order1(TreeNode* node)
	{
		if (node != NULL)
		{
			std::cout << node->val;
			pre_order1(node->left);
			pre_order1(node->right);
		}
	}

	// 前序遍历(栈法)
	void pre_order2(TreeNode* node) {
		if (node == NULL) {
			return;
		}
		std::vector<TreeNode*> stac;
		std::vector<int> result;
		stac.push_back(node);

		while (stac.size() > 0) {
			// 弹出最后一个元素
			TreeNode* tmp = stac.back();
			result.push_back(tmp->val);
			stac.pop_back();

			// 先入右子树
			if (tmp->right != NULL) {
				stac.push_back(tmp->right);
			}

			// 最后入左子树 (因为要先弹出来)
			if (tmp->left != NULL) {
				stac.push_back(tmp->left);
			}
		}
	}

	// 中序遍历(递归法)
	void mid_order1(TreeNode* node)
	{
		if (node != NULL)
		{
			pre_order1(node->left);
			std::cout << node->val;
			pre_order1(node->right);
		}
	}

	// 中序遍历(栈法)
	void mid_order2(TreeNode* node) {
		if (node == NULL) {
			return;
		}

		std::vector<int> result;
		std::vector<TreeNode*> treelist;
		TreeNode* p;

		p = node;

        // 思路: 只要该节点有左子树就进栈, 直到没得再进, 再开始弹出, 然后又看它的左子树

		while (p != NULL || treelist.size() > 0) {
			// 左子树全部进栈
			while (p != NULL) {
				treelist.push_back(p);
				p = p->left;
			}

			p = treelist.back();  // 取栈顶元素
			treelist.pop_back();  // 删除栈顶元素
			result.push_back(p->val);  // 结果

			// 右子树的左子树全部进栈
			p = p->right;
		}
	}


	// 后序遍历(递归法)
	void after_order1(TreeNode* node) {
		if (node != NULL) {
			after_order1(node->left);
			after_order1(node->right);
			std::cout << node->val;
		}
	}

	// 后序遍历(栈法)
	void after_order2(TreeNode* node) {
		std::vector<TreeNode*> stack;
		std::vector<int> result;
		TreeNode* p;

		stack.push_back(node);

		while (stack.size() > 0) {
			p = stack.back();
			result.push_back(p->val);
			stack.pop_back();

			if (p->left != NULL) {
				stack.push_back(p->left);
			}
			if (p->right != NULL) {
				stack.push_back(p->right);
			}
		}

		reverse(result.begin(), result.end());
	}
	
	// 层次遍历(队列)
	std::vector<int> level_order1(TreeNode* node) {
		if (node == NULL) {
			return std::vector<int>(0);
		}
		std::vector<int> result;
		std::queue<TreeNode*> que;
		que.push(node);  // 先把根节点加入

		while (!que.empty()) {
			TreeNode* tmp = que.front();  // 取队列第一个元素
			que.pop();  // 弹出(删除)第一个元素
			result.push_back(tmp->val);

			// 把左子树加入队列
			if (tmp->left != NULL) {
				que.push(tmp->left);
			}
			// 把右子树加入队列
			if (tmp->right != NULL) {
				que.push(tmp->right);
			}
		}

		return result;
	}


	// 层次遍历, 输出每层最左边那个数
	std::vector<int> level_order2(TreeNode* node) {
		if (node == NULL) {
			return std::vector<int>(0);
		}

		std::vector<int> result;
		std::queue<TreeNode*> que;
		TreeNode* tmp;

		que.push(NULL);  // NULL是标志位, 表示下一位将会是该层最左边的数
		que.push(node);

		while (que.size() > 0) {
			tmp = que.front();
			que.pop();
			
			// 读到了标志位, 则下一个数是最左边的数, 取出来, 并且再次置入标志位
			if (tmp == NULL) {
				if (que.empty()) {
					break;  // 若队列已空, 则退出, 这是处理到最后一个了, 结束条件
				}

				tmp = que.front();
				que.pop();
				result.push_back(tmp->val);
				que.push(NULL);
			}

			if (tmp->left) {
				que.push(tmp->left);
			}
			if (tmp->right) {
				que.push(tmp->right);
			}
		}

		return result;
	}

	// 从数组创建完全二叉树
	void CreateTree(TreeNode*& bt, int* a, int len, int index)
	{
		//从数组a中创建二叉树，len为数组a的长度-1。index初始值为0。
		if (index >= len) return;
		bt = new TreeNode(a[index]);
		CreateTree(bt->left, a, len, 2 * index + 1);
		CreateTree(bt->right, a, len, 2 * index + 2);
	}

	// 从前序遍历和中序遍历创建二叉树
	TreeNode* CreateTree2(const int* pre, const int* mid, int length) {
		/*******************************************************************
			pre: 前序遍历的数组指针, 如 [3] 2  1  5  4  8  7  9
			mid: 中序遍历的数组指针, 如  1  2 [3] 4  5  7  8  9
			length: 前序指针和中序指针的数组长度（两个一样长）
			https://blog.csdn.net/jjwwwww/article/details/85799421
		********************************************************************/

		// 递归结束条件
		if (pre == NULL || mid == NULL || length < 0) {
			return NULL;
		}

		// 建立根节点
		TreeNode* head = new TreeNode(pre[0]);

		// 找到根节点在中序遍历的位置
		int index = 0;
		while (index < length) {
			if (head->val == mid[index]) {
				break;
			}
			index++;
		}

		head->left = CreateTree2(pre + 1, mid, index);
		head->right = CreateTree2(pre + index + 1, mid + index + 1, length - index - 1);

		return head;
	}

};
