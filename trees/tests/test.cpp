#include <iostream>
#include <sstream>
#include "trees/tree.hpp"
#include <cstring>

int main(int nargs, char** vargs){
	trees::Tree treeSO;
	treeSO.setRoot(new trees::TreeNode("/"));
	std::string dir = "";
	std::string op="";
	std::string name="";
	std::string file="";
	trees::TreeNode* curr = treeSO.find("/");
	curr->setType(1); //root is a folder
	std::cout << "$TreeSO!\n\n¡Bienvenid@ a TreeSO!\n\n¡Autores: Vicente Romero, Matias Muñoz!"<<std::endl;
	while (op.compare("exit")!=0)
	{

		//INPUT PARSING
		std::cout<<dir<<"#";
		std::string input;
		std::getline(std::cin, input);
		std::istringstream ss(input);
		if (ss){
			ss >> op;
		}
		if (ss){
			ss >> name;
		}
		if (ss){
			ss >> file;
		}
		std::cout<<std::endl;
		//---------------------


		//OP-----------------------
		if (op.compare("mkdir")==0)
		{
			
			treeSO.insert(name, curr->getData());
			treeSO.find(name)->setParent(curr);
			treeSO.find(name)->setType(1);
			
			
		}
		else if (op.compare("mkfile")==0)
		{
			
			treeSO.insert(name, curr->getData());
			treeSO.find(name)->setParent(curr);
			treeSO.find(name)->setType(0);
			
			
		}
		else if (op.compare("rm")==0)
		{
			if (treeSO.find(name)->getType()==1)
			{
				treeSO.find(name)->getChildren()->removeAll();
				curr->getChildren()->remove(name);
			}
			else{
				curr->getChildren()->remove(name);
			}
			
			
			
			
		}
		else if (op.compare("ls")==0)
		{
			trees::TreeNode* node = treeSO.find(curr->getData());
			node->getChildren()->print();
		}
		else if (op.compare("cd")==0)
		{

			trees::TreeNode* node = treeSO.find(curr->getData());
			trees::TreeList* children = node->getChildren();
			trees::TreeNode* parent = node->getParent();
			//WHERE THE F*CK IS THE PARENT???
			//update: turns out none of the nodes had a parent set
			//so "cd .." never worked

			
			if (name.compare("..")==0 && parent != nullptr)
			{
				curr = parent;
				dir.erase(dir.length()-name.length());
			}
			
			else if (!(children->isEmpty()))
			{
				if(children->find(name) != nullptr && children->find(name)->getType()==1){
					//Solved a bug with this if in the dumbest way posible at treeList.cpp :D
					curr = children->find(name);
					dir = dir+"/"+name;
				}
				else{
				std::cout<<"No such file or directory\n";
				}
			}
			else{
				std::cout<<"No such file or directory\n";
			}
			
		}
		else if (op.compare("tree")==0)
		{
			treeSO.traverse();
		}
		
	}
	
	
	return 0;
}
