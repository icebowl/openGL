int main() {
  // Create a random device and use it to generate a random seed
    std::random_device myRandomDevice;
    unsigned seed = myRandomDevice();
    
    // Initialize a default_random_engine with the seed
    std::default_random_engine myRandomEngine(seed);

    // Print some random values
    std::cout << myRandomEngine() << " " << std::endl;
    std::cout << myRandomEngine() << " " << std::endl;
    std::cout << myRandomEngine() << " " << std::endl;
}
