# sending_mails_using-_CPP

This repo contains a simple CPP project which runs on visual studio version 2019 and is used for mass mailing with more features than any other massmailing web services 
to send beautiful mails that can be either html mail or plain text mail with attachments


All you have to do is to download or clone this repo on your desktop or anywhere in disk and then open visual studio 2019 and click on "Open a local folder". Select cloned 
folder(Massmailing_using_CPP), click on "File" menu, select "New"->"Project from existing code" and then type enter key. Then a new window will be prompted click on "Next",
select the folder "Massmsilin_using_cpp" in "project location" and name it abc(anything) in "Project name", click on "next", select "Console application project" in "Project type"
, click on "next","next" and finally "finish" leaving everything as it is.
Please see the comments in the code for some CPP packages installment processes.

Download and install EAMailSend from link https://www.emailarchitect.net/webapp/download/easendmail.exe .If incase code doesn't runs correctly then search easendmailobj.tlh and 
easendmailobj.tli on your computer storage and copy and paste it in prject folder after deleting previous same files.

Run ther program and provide necessary informations about your email, passwords and recipients email addresses and other contents of email body.

Note:If you are sending html mail instead of plain text,remember that body.html in the project folder is the html body you will be sending. Either open it with notepad 
and paste your own html code  and save it or simply delete it and paste your own html file in the folder and name it as "body" with extension html(i.e.body.html). 

To send mails to many recipients at once, select all the email addresses from google sheet at once and paste it in recipients.txt available in project folder and save it.
And while selecting the recipients in console choose "from file".
You can also enter addreses one by one in console by selecting "from console" or write or delete addreses in recipients.txt text file through console a well.
