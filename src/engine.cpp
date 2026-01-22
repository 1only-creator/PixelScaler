#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/ocl.hpp>

// Open Source MIT License
// High-performance Upscaler Core

int main(int argc, char** argv) {
    if (argc < 3) return 1;

    cv::ocl::setUseOpenCL(true); // Enable Tensor GPU acceleration
    if (!cv::ocl::haveOpenCL()) {
        std::cerr << "GPU Acceleration not available, falling back to CPU." << std::endl;
    }

    cv::Mat frame = cv::imread(argv[1]);
    cv::UMat gpu_frame, gpu_resized;

    frame.copyTo(gpu_frame);
    
    // Using INTER_CUBIC for performance, or wrap an AI model here
    cv::resize(gpu_frame, gpu_resized, cv::Size(), 2.0, 2.0, cv::INTER_CUBIC);

    cv::imwrite(argv[2], gpu_resized);
    return 0;
}