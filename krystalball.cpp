#include <iostream>
#include <vector>
using namespace std;

struct SalesExecutive {
    int id;
    int sales;
    vector<SalesExecutive*> subordinates;
    SalesExecutive(int id, int sales) : id(id), sales(sales) {}
};

pair<int, vector<SalesExecutive*>> dfs(SalesExecutive* node) {
    if (!node) return {0, {}};
    int max_sales = node->sales;
    vector<SalesExecutive*> max_line = {node};
    for (auto child : node->subordinates) {
        auto [child_sales, child_line] = dfs(child);
        if (child_sales > max_sales) {
            max_sales = child_sales;
            max_line = {node};
            max_line.insert(max_line.end(), child_line.begin(), child_line.end());
        }
    }
    return {max_sales, max_line};
}

vector<int> lineWithHighestSales(SalesExecutive* root) {
    auto [_, line] = dfs(root);
    vector<int> res;
    for (auto se : line) res.push_back(se->id);
    return res;
}

vector<int> bonusDistribution(vector<SalesExecutive*> line, int bonus) {
    int budget_efficiency_bonus = 0.25 * bonus;
    int sales_efficiency_bonus = 0.75 * bonus;

    vector<int> num_subordinates;
    int total_subordinates = 0;
    for (auto se : line) {
        num_subordinates.push_back(se->subordinates.size());
        total_subordinates += se->subordinates.size();
    }
    vector<int> budget_efficiency_distribution;
    for (int n : num_subordinates)
        budget_efficiency_distribution.push_back(budget_efficiency_bonus * n / total_subordinates);

    vector<int> sales_figures;
    int total_sales = 0;
    for (auto se : line) {
        sales_figures.push_back(se->sales);
        total_sales += se->sales;
    }
    vector<int> sales_efficiency_distribution;
    for (int s : sales_figures)
        sales_efficiency_distribution.push_back(sales_efficiency_bonus * s / total_sales);

    vector<int> res;
    for (int i = 0; i < line.size(); i++)
        res.push_back(budget_efficiency_distribution[i] + sales_efficiency_distribution[i]);
    return res;
}

int main() {
    // Construct the organization hierarchy tree
    vector<SalesExecutive*> nodes = {
        new SalesExecutive(1, 10),
        new SalesExecutive(2, 12),
        new SalesExecutive(3, 7),
        new SalesExecutive(4, 4),
        new SalesExecutive(5, 17),
        new SalesExecutive(6, 6),
        new SalesExecutive(7, 3),
        nullptr,
        new SalesExecutive(8, 9),
        new SalesExecutive(9, 10),
        new SalesExecutive(10, 11),
        new SalesExecutive(11, 18),
        new SalesExecutive(12, 2),
        new SalesExecutive(13, 13),
        new SalesExecutive(14, 15),
        new SalesExecutive(15, 29),
        nullptr,
        new SalesExecutive(16, 8),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        new SalesExecutive(17, 18)
    };
    
    for (int i = 0; i < nodes.size(); i++) {
      if (!nodes[i]) continue;
      if (2*i+1 < nodes.size()) nodes[i]->subordinates.push_back(nodes[2*i+1]);
      if (2*i+2 < nodes.size()) nodes[i]->subordinates.push_back(nodes[2*i+2]);
   }

   // Find the organization line with the highest sales
   auto line = lineWithHighestSales(nodes[0]);

   // Calculate the bonus distribution
   vector<SalesExecutive*> line_nodes;
   for (int id : line)
       for (auto node : nodes)
           if (node && node->id == id)
               line_nodes.push_back(node);
   auto bonus = bonusDistribution(line_nodes, 3000000);

   // Print the results
   cout << "Employee ID Bonus" << endl;
   for (int i = 0; i < line.size(); i++)
       cout << "SE" << line[i] << " " << bonus[i] << endl;

   return 0;
}
