/**
 * @file polymorphism.cpp
 * @brief Demonstration of Compile-Time and Run-Time Polymorphism in C++
 * @course CMP2103 - Object-Oriented Programming with C++
 */

#include <iostream>
#include <string>
#include <vector>
#include <memory>

// ============================================================================
// PART 1: COMPILE-TIME POLYMORPHISM (STATIC BINDING)
// ============================================================================

// --- 1A. Function Overloading ---
class MathOperations {
public:
    // Overload 1: Multiply two integers
    int multiply(int a, int b) {
        return a * b;
    }

    // Overload 2: Multiply three integers
    int multiply(int a, int b, int c) {
        return a * b * c;
    }

    // Overload 3: Multiply two floating-point numbers
    double multiply(double a, double b) {
        return a * b;
    }
};

// --- 1B. Operator Overloading ---
class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    // Overloading the binary '+' operator to add two Vector2D instances
    Vector2D operator+(const Vector2D& rhs) const {
        return Vector2D(x + rhs.x, y + rhs.y);
    }

    // Overloading the stream insertion '<<' operator for clean printing
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& vec) {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }
};


// ============================================================================
// PART 2: RUN-TIME POLYMORPHISM (DYNAMIC BINDING)
// ============================================================================

// Abstract Base Class: MediaDevice
class MediaDevice {
protected:
    std::string deviceName;

public:
    MediaDevice(const std::string& name) : deviceName(name) {
        std::cout << "  [MediaDevice Constructor] Initializing base: " << deviceName << std::endl;
    }

    // Pure Virtual Function -> Makes MediaDevice an Abstract Base Class
    virtual void play() const = 0;

    // Virtual Function with Default Implementation
    virtual void displayInfo() const {
        std::cout << "Device Name: " << deviceName << " [Generic Media Device]" << std::endl;
    }

    // Virtual Destructor -> MANDATORY for safe dynamic memory cleanup
    virtual ~MediaDevice() {
        std::cout << "  [MediaDevice Destructor] Cleaning up base: " << deviceName << std::endl;
    }
};

// Derived Class 1: AudioPlayer
class AudioPlayer : public MediaDevice {
private:
    int bitrateKbps;

public:
    AudioPlayer(const std::string& name, int bitrate)
        : MediaDevice(name), bitrateKbps(bitrate) {
        std::cout << "  [AudioPlayer Constructor] Bitrate: " << bitrateKbps << " kbps" << std::endl;
    }

    // Overriding pure virtual function
    void play() const override {
        std::cout << "  [AudioPlayer Playing] Streaming high-fidelity audio (" 
                  << bitrateKbps << " kbps) on " << deviceName << std::endl;
    }

    // Overriding virtual display method
    void displayInfo() const override {
        std::cout << "Device: " << deviceName << " | Type: Audio Player | Bitrate: " 
                  << bitrateKbps << " kbps" << std::endl;
    }

    ~AudioPlayer() override {
        std::cout << "  [AudioPlayer Destructor] Releasing audio buffer for " << deviceName << std::endl;
    }
};

// Derived Class 2: VideoPlayer
class VideoPlayer : public MediaDevice {
private:
    std::string resolution;

public:
    VideoPlayer(const std::string& name, const std::string& res)
        : MediaDevice(name), resolution(res) {
        std::cout << "  [VideoPlayer Constructor] Resolution: " << resolution << std::endl;
    }

    // Overriding pure virtual function
    void play() const override {
        std::cout << "  [VideoPlayer Playing] Rendering " << resolution 
                  << " video stream on " << deviceName << std::endl;
    }

    // Overriding virtual display method
    void displayInfo() const override {
        std::cout << "Device: " << deviceName << " | Type: Video Player | Resolution: " 
                  << resolution << std::endl;
    }

    ~VideoPlayer() override {
        std::cout << "  [VideoPlayer Destructor] Releasing GPU render target for " << deviceName << std::endl;
    }
};


// ============================================================================
// MAIN EXECUTION ROUTINE
// ============================================================================
int main() {
    std::cout << "========================================================\n";
    std::cout << "   CMP2103: POLYMORPHISM DEMONSTRATION IN C++\n";
    std::cout << "========================================================\n\n";

    // ------------------------------------------------------------------------
    // SECTION 1: Compile-Time Polymorphism
    // ------------------------------------------------------------------------
    std::cout << "--- 1. COMPILE-TIME POLYMORPHISM DEMONSTRATION ---\n";
    
    // A. Function Overloading
    MathOperations math;
    std::cout << "[Function Overloading]\n";
    std::cout << "  math.multiply(4, 5)       = " << math.multiply(4, 5) << "\n";
    std::cout << "  math.multiply(2, 3, 4)    = " << math.multiply(2, 3, 4) << "\n";
    std::cout << "  math.multiply(2.5, 4.2)   = " << math.multiply(2.5, 4.2) << "\n\n";

    // B. Operator Overloading
    std::cout << "[Operator Overloading]\n";
    Vector2D v1(3.5, 2.0);
    Vector2D v2(1.5, 4.5);
    Vector2D v3 = v1 + v2; // Calls Vector2D::operator+
    
    std::cout << "  Vector 1: " << v1 << "\n";
    std::cout << "  Vector 2: " << v2 << "\n";
    std::cout << "  Vector 3 (v1 + v2): " << v3 << "\n\n";

    // ------------------------------------------------------------------------
    // SECTION 2: Run-Time Polymorphism
    // ------------------------------------------------------------------------
    std::cout << "--- 2. RUN-TIME POLYMORPHISM DEMONSTRATION ---\n";
    std::cout << "[Instantiating Polymorphic Objects via Base Class Pointers]\n";
    
    std::vector<MediaDevice*> playlist;
    playlist.push_back(new AudioPlayer("Sony Walkman", 320));
    playlist.push_back(new VideoPlayer("LG OLED TV", "4K Ultra HD"));

    std::cout << "\n[Executing Dynamic Dispatch via Base Pointers]\n";
    for (size_t i = 0; i < playlist.size(); ++i) {
        std::cout << "\nItem " << (i + 1) << ":\n";
        playlist[i]->displayInfo(); // Dynamically bound call
        playlist[i]->play();        // Dynamically bound call
    }

    std::cout << "\n[Polymorphic Destruction via Virtual Destructor]\n";
    for (MediaDevice* device : playlist) {
        delete device; // Ensures derived destructor runs first, then base destructor
        std::cout << "  ----------------------------------------\n";
    }

    std::cout << "\n========================================================\n";
    std::cout << "   DEMONSTRATION COMPLETED SUCCESSFULLY\n";
    std::cout << "========================================================\n";

    return 0;
}
