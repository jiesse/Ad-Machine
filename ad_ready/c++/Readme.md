#interface lib


    qt (multi-platform) 
    vc++ mfc
    minigui
#play vedio

    mplayer

#vmware tools

    cd /cdrom1
    cd /VMware Tools
    mv vmwaretools /home/jiesse
    tar  zxvf ..
    cd vmwaretools..
    sudo perl ....pl
    (next all default)

# ifconfig eth0 10.1.14.255  (rewrite ip)
    ping 10.1.14.254   (ping gateway)
    ifconfig  : detail ip msg ; eth0 , gateway ,etc

#qt

    sudo apt-get install built-essential  (g++)
    g++ c++
    gcc c

#c++

#qt


    not use IDE but make in terminal:

    install qt
    cd     /usr/bin 
    sudo ln -s /home/jiesse/qt-2010-5/qt/bin/qmake

    qmake  -project
    qmake
    make
    ./QT1
    
#httpd

    install httpd

    tar zxvf httpd-2.2.4.tar.gz

    ./configure -prefix=/var/httpd

    make

    sudo make install

    ./htdocs : put *.html

    ./cgi-bin :  put *.cgi

    sudo /var/httpd/bin/httpd  -k start

    cd ./conf

    vi http.conf

    add comment : ServerName 127.0.0.1:80   ;( ip stand for host , 80 default the process port)

    then : at firefox : input http://127.0.0.1/index.html

#ssh

    ssh : secure shell

    scp ./filename username@10.1.14.39 :/home/username/directory  note: ':'
    two sides not have blank

    scp username@10.1.14.39 filename ./directorr

    scp -r username@10.1.14.39 : directory  ./   : ok

    scp -r directory username@10.1.14.39: /home/username/   :ok


    ssh usename@10.1.14.xx
     
    ssh exit : exit 
















