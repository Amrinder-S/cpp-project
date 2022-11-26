
void createBox(int x, int y, int size_x, int size_y, int color)
{
size_x += x;
size_y += y;

print(0,0,0,15," ");
std::cout<<"x = "<<x<<", y = "<<y<<", size_x = "<<size_x<<", size_y = "<<size_y;

print(x,y,0,118," ");
print(x+1,y+1,0,15,"(x,y="+std::to_string(x)+","+std::to_string(y)+")");
print(size_x,y,0,118," ");
print(size_x+1,y+1,0,15,"(size_x,y="+std::to_string(size_x)+","+std::to_string(y)+")");

print(x,size_y,0,118," ");
print(x-3,size_y-3,0,16,"(x="+std::to_string(x)+",size_y="+std::to_string(size_y)+")");


print(size_x, size_y, 0, 118, " ");
print(size_x+1, size_y+1, 0,15,"(size_x="+std::to_string(size_x)+",size_y="+std::to_string(size_y)+")");

}