**Q**:  
	7.7 Shared library  
	`gcc -static hello1.c`  
	prevent gcc from using shared library  
	Error:  
		/usr/bin/ld: cannot find -lc  
		collect2: error: ld returned 1 exit status  
**A**:  
	[Solution1](https://www.cnblogs.com/zhming26/p/6164131.html)  Fail!  
	`sudo echo '...' >> /etc/ld.so.conf` error  
	[Solution](https://blog.csdn.net/yunyi4367/article/details/78070928)   

**Q**:  
	gcc option  
**A**:  
	[runoob.com](http://www.runoob.com/w3cnote/gcc-parameter-detail.html)  
	-c activate preprocessing, compiling and assembling ——> obj xxx.c->xxx.o  
	-S activate preprocessing and compiling ——> .s  
    -static forbid using DLL, so a little bit larger than normal  
	-share try to use DLL, so smaller.  
	-g just compile with producing debugging info  
	-O0 -O1 -O2 -O3 compiler optimization, default -O1, the optimization level highest -O3, -O0 no optimization  
	-l -lxxx specify libxxx.a/so using for compiling  
	-o generate a specified output file 
	-Wall generate all warnings  
	-w generate no warning 
	-L specify the path of library explicitly 

**Q**:  
	lib\.a\.so?  
**A**:
	[imxiangzi](https://blog.csdn.net/imxiangzi/article/details/45871949)  

	solve dependency between libraries:  
		1. /etc/ld.so.conf.d/name-of-lib-x86_64.conf / /etc/ld.so.conf.d/name-of-lib-i686.conf  add path of unfound library, then sudo ldconfig or reload /etc/ld/so.cache  
		2. specify explicitly the path of lib, such as -lname-of-lib -L/path/to/lib  
		3. export LD_LIBRARY_PATH = $LD_LIBRARY_PATH:/path/to/lib   
	ldconfig: config dynamic link runtime binding  
	ldd: list lib dependency info  
	ld: GNU compiler

	**lib path**  
		1. add to /etc/ld.so.conf, then `sudo ldconfig` [ldconfig](https://linux.die.net/man/8/ldconfig)  
		2. add specified directory to libcache  
			`sudo ldconfig -n /opt/lib` 
		   in this way you cannot contain relevant directories permanently, lose after the system restart.
		3. configurate LD_LIBRARY_PATH 

	**ar**: (ar)[http://www.runoob.com/linux/linux-comm-ar.html]  
		`ar tf ***.a`	list .obj file in lib  

**Q**:  
	ln command?  
**A**:  
	[runoob](http://www.runoob.com/linux/linux-comm-ln.html)  

**Q**:  
	gcc command?  
**A**:  
	[runoob](http://www.runoob.com/w3cnote/gcc-parameter-detail.html)  

**Q**:  
	cannot open shared object file: No such file or directory  
**A**:  
	[SmartVessel](http://www.cnblogs.com/smartvessel/archive/2011/01/21/1940868.html)  


	
		


