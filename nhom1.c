#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
int main()

{
    printf("\n DANH SACH NHOM BAI TAP LON HE DIEU HANH \n");
    printf("\n==============================================================\n");
    printf("%4s | %-30s | %-20s |", "STT", "Ho va ten", "Ma so sinh vien");
    printf("\n==============================================================\n");
    printf("%4s | %-30s | %-20s |", "01", "Dang Tuan Anh", "20150035");
    printf("\n%4s | %-30s | %-20s |", "02", "Nghiem Tuan Anh", "20150081");
    printf("\n%4s | %-30s | %-20s |", "03", "Do Thanh An", "20140006");
    printf("\n%4s | %-30s | %-20s |", "04", "Dinh Duy Anh", "20150036");
    printf("\n==============================================================\n");

    sleep(5);
    printf("day la tien trinh %d\n",getpid());
    pid_t pid1, pid2, pid3, pid4, pid5;
    pid1=fork();
if(pid1==0)
  {
    printf("child1 = %d + parent %d\n",getpid(),getppid());
	//ma hoa video bang chuan H264
    system("ffmpeg -i dtaabc.mp4 -c:v libx264 -preset slow -crf 22 -c:a copy output1.mp4 ");
    system("echo dung luong cua video la");
	// in ra man hinh dung luong cua video sau khi da chuyen doi
    system("du -ah output1.mp4");
	// thay the tien trinh con bang tien trinh mplayer
    execl("/usr/bin/mplayer","mplayer","output1.mp4",NULL);
    exit(0);
  }

    pid2=fork();
if(pid2==0)
  { 
    sleep(20);
    printf("child2 = %d + parent %d\n",getpid(),getppid());
    //system("ffmpeg -i NTA.mp4 -c:v libx264 -preset slow -crf 22 -c:a copy output2.mp4 ");
    system("echo dung luong cua video la");
    system("du -ah output1.mp4");
    execl("/usr/bin/mplayer","mplayer","output2.mp4",NULL);
    exit(0);
  }

  pid3=fork();
  if(pid3==0)
  { 
    sleep(40);
    printf("child3 = %d + parent %d\n",getpid(),getppid());
    //system("ffmpeg -i DTA.mp4 -c:v libx264 -preset slow -crf 22 -c:a copy output3.mp4 ");
    system("echo dung luong cua video la");
    system("du -ah output3.mp4");
    execl("/usr/bin/mplayer","mplayer","output3.mp4",NULL);
    exit(0);
  }

  pid4=fork();
  if(pid4==0)
  {
    sleep(60);
    printf("child4 = %d + parent %d\n",getpid(),getppid());
    //system("ffmpeg -i DDA.mp4 -c:v libx264 -preset slow -crf 22 -c:a copy output4.mp4 ");
    system("echo dung luong cua video la");
    system("du -ah output4.mp4");
    execl("/usr/bin/mplayer","mplayer","output4.mp4",NULL);
    exit(0);
  }

  pid5=fork();
  if(pid5==0)
  {
    printf("child5 = %d + parent %d\n",getpid(),getppid());
    exit(0);
  }

  sleep(3);
  while(1)
{   system("ps -C mplayer -o pid,%cpu,%mem");  
    sleep(3);
}

return 0;


}
