/*
 * tree.hpp
 *
 *  Created on: Aug 31, 2022
 *      Author: jsaavedr
 */

#ifndef TREE_HPP_
#define TREE_HPP_

#include "trees/treeNode.hpp"


namespace trees {

class Tree {
private:
	TreeNode* root;
public:
	Tree();
	void setRoot(TreeNode* node);
	void insert(TreeNode* node, TreeNode* parent);
	void insert(std::string child, std::string parent);
	TreeNode* find_rec(std::string val, TreeNode* node);
	TreeNode* find(std::string val);
	void traverse_rec(TreeNode* node, int level);
	void traverse_find(TreeNode* root, TreeNode* node, std::string val);
	std::string path(TreeNode* root, TreeNode* start);
	void traverse();
	virtual ~Tree();
};

} /* namespace trees */

#endif /* TREE_HPP_ */
