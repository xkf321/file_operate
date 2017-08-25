obj = file_1.o  #相当于宏定义

file_1:$(obj)
	gcc -ggdb3 -Wall -o  file_1 $(obj)

file_1.o:file_1.c 
	gcc -c $<   #-I后是需要头文件的路径

.PHONY:clean
clean:
	rm $(obj)
	
.PHONY:cleanall
cleanall:
	rm $(obj) file_1




