#include <string>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/io/pcd_io.h>
#include <pcl/common/transforms.h>
#include <jsoncpp/json/json.h> 

#include <liblas/liblas.hpp>


typedef pcl::visualization::PCLVisualizer PCLVisualizer;

std::string pcd_path = "Lidar.las";

int main(int argc, char **argv){

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ptr(new pcl::PointCloud<pcl::PointXYZ>);

    std::ifstream ifs(pcd_path, std::ios::in | std::ios::binary);
    liblas::ReaderFactory f;
    liblas::Reader reader = f.CreateWithStream(ifs);
    cloud_ptr->width    = reader.GetHeader().GetPointRecordsCount();
    cloud_ptr->height   = 1;
    cloud_ptr->is_dense = false;
    cloud_ptr->points.resize (cloud_ptr->width * cloud_ptr->height);

    int i=0;
    while(reader.ReadNextPoint())
    {
        cloud_ptr->points[i].x = (reader.GetPoint().GetX());
        cloud_ptr->points[i].y = (reader.GetPoint().GetY());
        cloud_ptr->points[i].z = (reader.GetPoint().GetZ());
        i++;
    }

    pcl::io::savePCDFileBinary("Lidar.pcd", *cloud_ptr);
    std::cout << "Save successfully!" << std::endl;

    return 0;
}


