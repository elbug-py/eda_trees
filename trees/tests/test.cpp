#include <iostream>
#include <sstream>
#include "trees/tree.hpp"
#include <cstring>

int main(int nargs, char** vargs){
	trees::Tree treeSO;
	treeSO.setRoot(new trees::TreeNode("/"));
	std::string dir = "/";
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
		op="";name="";file="";
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
			trees::TreeNode* insert = new trees::TreeNode();
			insert->setType(1);
			if (file.compare("")==0)
			{
				if (curr->getType()==1)
				{
					insert->setParent(curr);
					insert->setData(name);
					curr->getChildren()->insertFirst(insert);
				}
				else{
					std::cout<<"Not a folder\n";
				}
				
				
			}
			else if (name.compare(".")==0)
			{
				if (curr->getType()==1)
				{
					insert->setParent(curr);
					insert->setData(file);
					curr->getChildren()->insertFirst(insert);
				}
				else{
					std::cout<<"Not a folder\n";
				}
			}
			else if (name.compare("..")==0)
			{
				if (curr->getParent()!=nullptr && curr->getParent()->getType()==1)
				{
					insert->setParent(curr->getParent());
					insert->setData(file);
					curr->getParent()->getChildren()->insertFirst(insert);
				}
				else{
					std::cout<<"Not a folder\n";
				}
			}
			else{
				std::string path;
				trees::TreeNode* node = new trees::TreeNode;
				node=curr;
				int i = 1;
				for (;i < name.length(); i++)
				{
					if (name[i]!='/')
					{
						path += name[i];
					}
					else{
						if (node->getChildren()!= nullptr && node->getChildren()->find(path)!=nullptr)
						{
							node = node->getChildren()->find(path);
							path="";
						}
						else{
							node = nullptr;
							break;
						}
					}
				}

				if (node->getChildren()!= nullptr && node->getChildren()->find(path)!=nullptr)
						{
							node = node->getChildren()->find(path);
						}
				else{
					node = nullptr;
					}

				if (node != nullptr && node->getType()==1)
				{
					insert->setParent(node);
					insert->setData(file);
					node->getChildren()->insertFirst(insert);
				}
				else{
					std::cout<<"Path Error"<<std::endl;
				}
			}		
		}
		else if (op.compare("mkfile")==0)
		{
			trees::TreeNode* insert = new trees::TreeNode();
			insert->setType(0);
			if (file.compare("")==0){
				if (curr->getType()==1)
				{
					insert->setParent(curr);
					insert->setData(name);
					curr->getChildren()->insertFirst(insert);
				}
				else{
					std::cout<<"Not a folder\n";
				}
			}
			else if (name.compare(".")==0)
			{
				if (curr->getType()==1)
				{
					insert->setParent(curr);
					insert->setData(file);
					curr->getChildren()->insertFirst(insert);
				}
				else{
					std::cout<<"Not a folder\n";
				}
			}
			else if (name.compare("..")==0)
			{
				if (curr->getParent()!=nullptr && curr->getParent()->getType()==1)
				{
					insert->setParent(curr->getParent());
					insert->setData(file);
					curr->getParent()->getChildren()->insertFirst(insert);
				}
				else{
					std::cout<<"Not a folder\n";
				}
			}
			else{
				std::string path;
				trees::TreeNode* node = new trees::TreeNode;
				node=curr;
				int i = 1;
				for (;i < name.length(); i++)
				{
					if (name[i]!='/')
					{
						path += name[i];
					}
					else{
						if (node->getChildren()!= nullptr && node->getChildren()->find(path)!=nullptr)
						{
							node = node->getChildren()->find(path);
							path="";
						}
						else{
							node = nullptr;
							break;
						}
					}
				}
				
				if (node->getChildren()!= nullptr && node->getChildren()->find(path)!=nullptr)
						{
							node = node->getChildren()->find(path);
						}
				else{
					node = nullptr;
					}

				if (node != nullptr && node->getType()==1)
				{
					
					insert->setParent(node);
					insert->setData(file);
					node->getChildren()->insertFirst(insert);
				}
				else{
					std::cout<<"Path Error"<<std::endl;
				}
			}
		}
		else if (op.compare("rm")==0)
		{
			if (file.compare("")==0){
				if (curr->getChildren()->find(name)->getType()==1)
				{
					curr->getChildren()->find(name)->getChildren()->removeAll();
					curr->getChildren()->remove(name);
				}
				else{
					curr->getChildren()->remove(name);
				}
			}
			else if (name.compare(".")==0)
			{
				if (curr->getChildren()->find(file)->getType()==1)
				{
					curr->getChildren()->find(file)->getChildren()->removeAll();
					curr->getChildren()->remove(file);
				}
				else{
					curr->getChildren()->remove(file);
				}
			}
			
			
		}
		else if (op.compare("ls")==0)
		{
			trees::TreeNode* node = curr;
			if (name.compare(".")==0 || name.compare("")==0)
			{
				curr->getChildren()->print();
			}
			else if (name.compare("..")==0)
			{
				if (curr->getParent()!=nullptr)
				{
					curr->getParent()->getChildren()->print();
				}
				else{
					std::cout<<"Path error\n";
				}
			}
			else{
				std::string path;
				trees::TreeNode* node = new trees::TreeNode;
				node=curr;
				int i = 1;
				for (;i < name.length(); i++)
				{
					if (name[i]!='/')
					{
						path += name[i];
					}
					else{
						if (node->getChildren()!= nullptr && node->getChildren()->find(path)!=nullptr)
						{
							node = node->getChildren()->find(path);
							path="";
						}
						else{
							node = nullptr;
							break;
						}
					}
				}

				if (node->getChildren()!= nullptr && node->getChildren()->find(path)!=nullptr)
						{
							node = node->getChildren()->find(path);
						}
				else{
					node = nullptr;
					}

				if (node != nullptr)
				{
					node->getChildren()->print();
				}
				else{
					std::cout<<"Path Error"<<std::endl;
				}
			}
		}
		else if (op.compare("cd")==0)
		{

			trees::TreeNode* node = curr;
			//trees::TreeList* children = node->getChildren();
			trees::TreeNode* parent = node->getParent();
			//update: turns out none of the nodes had a parent set
			//so "cd .." never worked

			
			if (name.compare("..")==0 && parent != nullptr)
			{
				curr = parent;
				dir.erase(dir.length()-node->getData().length()-1);
			}
			else{
				std::string path;
				std::string pathReal="";
				node=curr;
				int i = 1;
				for (;i < name.length(); i++)
				{
					if (name[i]!='/')
					{
						path += name[i];
					}
					else{
						if (node->getChildren()!= nullptr && node->getChildren()->find(path)!=nullptr)
						{
							node = node->getChildren()->find(path);
							pathReal += path;
							pathReal += "/";
							path="";
						}
						else{
							node = nullptr;
							break;
						}
					}
				}

				if (node->getChildren()!= nullptr && node->getChildren()->find(path)!=nullptr)
						{
							node = node->getChildren()->find(path);
							pathReal += path;
							pathReal += "/";
							path="";
						}
				else{
					node = nullptr;
					}

				if (node != nullptr)
				{
					curr=node;
					dir += pathReal;
				}
				else{
					std::cout<<"Path Error"<<std::endl;
				}
			}
		}
		else if (op.compare("tree")==0)
		{	if(name.compare("")==0){
				trees::TreeNode* node = curr;
				treeSO.traverse_rec(node,1);
			}
			else if (name.compare(".")==0)
			{
				treeSO.traverse_rec(curr, 1);
			}
			else if (name.compare("..")==0)
			{
				if (curr->getParent()!=nullptr)
				{
					treeSO.traverse_rec(curr->getParent(), 1);
				}
				else{
					std::cout<<"Path error\n";
				}
			}
			else{
				std::string path;
				trees::TreeNode* node = new trees::TreeNode;
				node=curr;
				int i = 1;
				for (;i < name.length(); i++)
				{
					if (name[i]!='/')
					{
						path += name[i];
					}
					else{
						if (node->getChildren()!= nullptr && node->getChildren()->find(path)!=nullptr)
						{
							node = node->getChildren()->find(path);
							path="";
						}
						else{
							node = nullptr;
							break;
						}
					}
				}

				if (node->getChildren()!= nullptr && node->getChildren()->find(path)!=nullptr)
						{
							node = node->getChildren()->find(path);
						}
				else{
					node = nullptr;
					}

				if (node != nullptr)
				{
					treeSO.traverse_rec(node, 1);
				}
				else{
					std::cout<<"Path Error"<<std::endl;
				}
			}
		}
		else if (op.compare("find")==0)
		{
			trees::TreeNode* node = curr;
			if (name.compare(".")==0)
			{
				treeSO.traverse_find(node, node,file);
			}
			else if (name.compare("..")==0)
			{
				if (curr->getParent()!=nullptr)
				{
					treeSO.traverse_find(curr->getParent(),curr->getParent(), file);
				}
				else{
					std::cout<<"Path error\n";
				}
			}
			else{
				std::string path;
				trees::TreeNode* node = new trees::TreeNode;
				node=curr;
				int i = 1;
				for (;i < name.length(); i++)
				{
					if (name[i]!='/')
					{
						path += name[i];
					}
					else{
						if (node->getChildren()!= nullptr && node->getChildren()->find(path)!=nullptr)
						{
							node = node->getChildren()->find(path);
							path="";
						}
						else{
							node = nullptr;
							break;
						}
					}
				}

				if (node->getChildren()!= nullptr && node->getChildren()->find(path)!=nullptr)
						{
							node = node->getChildren()->find(path);
						}
				else{
					node = nullptr;
					}
				
				if (node != nullptr)
				{
					treeSO.traverse_find(node,node,file);
				}
				else{
					std::cout<<"Path Error"<<std::endl;
				}
			}
		}
	}
	
	
	return 0;
}
