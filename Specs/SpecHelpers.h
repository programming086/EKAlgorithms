
#import <Foundation/Foundation.h>
#import <Kiwi/Kiwi.h>

// Declare an external function for benchmarking code performance.
// `dispatch_benchmark` runs a given block of code `count` times and returns the time taken in nanoseconds.
FOUNDATION_EXPORT uint64_t dispatch_benchmark(size_t count, void (^block)(void));

// Define an inline function to benchmark code execution and log the results.
// `Benchmark` is a static inline function that measures and logs the average execution time of a code block.
static inline void Benchmark(size_t n, void(^block)(void)) {
    // Call `dispatch_benchmark` with `n` iterations and the provided block of code.
    // Store the total execution time in nanoseconds.
    float time = (float)dispatch_benchmark(n, block);

    // Log the number of iterations and the average time per iteration in milliseconds.
    // `time / 1000000` converts the time from nanoseconds to milliseconds.
    NSLog(@"The block have been run %zu times. Average time is %f milliseconds",  n, (time / 1000000));
}
