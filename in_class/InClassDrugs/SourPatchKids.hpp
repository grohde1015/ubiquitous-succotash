#include <iostream>
#include <memory>
#include <vector>

class SourPatch{
    public:
        SourPatch(std::string ingredients){

        }
    
    
}

class Drug{    
    public:
        void Drug(std::string name, std::vector<Ingredient>* ingredientList);

        virtual std::string getName() = 0;
        virtual std::vector<Ingredient>* getIngredients() = 0;

    protected:
        std::string name;
        std::vector<Ingredient>* ingreds;
};

class Ingredient{
    public:
        void Ingredient(std::string name, int quantity, std::string path);
        void Ingredient(std::string name, std::string path);

        virtual std::string getName() = 0;
        virtual std::string getPath() = 0;
        virtual int getQuantity() = 0;
        virtual void setQuantity(int quantity) = 0;

    protected:
        std::string name;
        std::string path;
        int quantity = 0;
};

class DrugFactory{

	public:
		virtual Drug* makeDrug() = 0; // VIRTUAL factory method- lets your subclass define how something is produced
		virtual shipDrug() = 0; // Make sure there's a way to update the drug warehouse
	
	private:
		std::string drug_warehouse_path;
	
};