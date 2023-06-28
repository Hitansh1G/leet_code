#include <iostream>
#include <vector>
include namespace std;


int calculateDroppedPackets(std::vector<std::vector<int> >& requests, int rate, int max_packets) {
    int total_packets = 0;
    int dropped_packets = 0;
    
    for (auto& request : requests) {
        int time = request[0];
        int packets = request[1];
        
        total_packets += packets;
        
        if (total_packets > max_packets) {
            int extra_packets = total_packets - max_packets;
            int packets_to_drop = extra_packets - rate * time;
            dropped_packets += std::max(0, packets_to_drop);
        }
    }
    
    return dropped_packets;
}

int main() {
    std::vector<std::vector<int> > requests = {{1, 8}, {4, 9}, {6, 7}};
    int rate = 2;
    int max_packets = 10;
    
    int dropped_packets = calculateDroppedPackets(requests, rate, max_packets);
    std::cout << "Total number of dropped packets: " << dropped_packets << std::endl;
    
    return 0;
}
