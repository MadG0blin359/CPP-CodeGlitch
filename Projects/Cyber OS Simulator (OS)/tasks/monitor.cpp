#include <iostream>
#include <string>
#include <vector>
#include <unistd.h> // For sleep
#include <iomanip> // For formatting output

using namespace std;

// Function to simulate getting CPU usage
float getCPUUsage() {
    // In a real system, this would involve reading system files
    // like /proc/stat on Linux or using OS-specific APIs.
    // For this simulation, we'll just return a random value.
    return (float)(rand() % 1000) / 10.0f; // Returns a float between 0.0 and 100.0
}

// Function to simulate getting memory usage
pair<float, float> getMemoryUsage() {
    // In a real system, this would involve reading /proc/meminfo on Linux
    // or using GlobalMemoryStatusEx on Windows.
    // For this simulation, we'll return random values.
    float totalMemory = 8192.0f + (rand() % 8192); // Simulate total memory between 8GB and 16GB
    float usedMemory = (float)(rand() % (int)totalMemory);
    return {usedMemory, totalMemory};
}

// Function to simulate getting disk usage for a specific path
pair<float, float> getDiskUsage(const string& path) {
    // In a real system, this would involve using statvfs on Linux or
    // GetDiskFreeSpaceEx on Windows.  For the simulation, we'll use
    // a fixed total, and a random used amount.
    float totalSpace = 1000.0f; // 1000 GB
    float usedSpace = (float)(rand() % (int)totalSpace);
    return {usedSpace, totalSpace};
}

// Function to simulate getting network usage
pair<float, float> getNetworkUsage() {
    //  In a real system, this is very complex and involves reading
    //  interface statistics.  Here, we just return random values.
    float sentData = (float)(rand() % 1000);      // in MB
    float receivedData = (float)(rand() % 1500);  // in MB
    return {sentData, receivedData};
}

int main() {
    cout << "Starting System Monitor...\n";

    while (true) {
        // Clear the screen (for a more dynamic display)
        cout << "\033[2J\033[1;1H";

        cout << "╔══════════════════════════════════════════════╗\n";
        cout << "║                 System Monitor                 ║\n";
        cout << "╚══════════════════════════════════════════════╝\n";

        // Get and display CPU usage
        float cpuUsage = getCPUUsage();
        cout << "CPU Usage:     " << fixed << setprecision(1) << cpuUsage << "%\n";

        // Get and display memory usage
        pair<float, float> memoryUsage = getMemoryUsage();
        cout << "Memory Usage:  " << fixed << setprecision(1) << memoryUsage.first << " MB / "
                  << memoryUsage.second << " MB ("
                  << (memoryUsage.first / memoryUsage.second) * 100.0f << "%)\n";

        // Get and display disk usage
        pair<float, float> rootDiskUsage = getDiskUsage("/"); // Monitor root partition
        cout << "Disk Usage (/): " << fixed << setprecision(1) << rootDiskUsage.first << " GB / "
                  << rootDiskUsage.second << " GB ("
                  << (rootDiskUsage.first / rootDiskUsage.second) * 100.0f << "%)\n";

        // Get and display network usage
        pair<float, float> networkUsage = getNetworkUsage();
        cout << "Network Sent:    " << fixed << setprecision(1) << networkUsage.first << " MB\n";
        cout << "Network Received: " << fixed << setprecision(1) << networkUsage.second << " MB\n";

        cout << "------------------------------------------------------\n";
        cout << "Press Ctrl+C to exit...\n";

        // Wait for a short period before updating again.
        sleep(2);
    }

    cout << "Exiting System Monitor.\n";
    return 0;
}

