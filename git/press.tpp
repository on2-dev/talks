--title git - the stupid content tracker
--author Williams
--date today

--newpage intro
--heading o que é esse tal de git ?

* gerenciador de versões
* criado em 2005 para substituir BitKeeper
* trabalha com snapshots
* historico local


--newpage init
--heading iniciando um repositório...

local.
--beginshelloutput
$ git init
Initialized empty Git repository in demo/.git/
--endshelloutput
---
remoto.
--beginshelloutput
$ git clone https://gitlab.com/developer/demo.git 
Cloning into 'demo'...
remote: Enumerating objects: 5029, done.
remote: Counting objects: 100% (5029/5029), done.
remote: Compressing objects: 100% (3402/3402), done.
--endshelloutput
---
urls suportadas
*   ssh://[user@]host.xz[:port]/path/to/repo.git/
*   git://host.xz[:port]/path/to/repo.git/
*   http[s]://host.xz[:port]/path/to/repo.git/
*   ftp[s]://host.xz[:port]/path/to/repo.git/

--newpage .git
--heading tá, mas e esse .git aqui?

--beginshelloutput
$ ls -la
drwxr-xr-x 7 developer developer 4096 Jun  7 10:16 .git
--endshelloutput
---
--beginshelloutput
$ cd .git && ls -la
drwxr-xr-x 2 developer developer 4096 Jun  7 09:55 branches
-rw-r--r-- 1 developer developer   92 Jun  7 09:55 config
-rw-r--r-- 1 developer developer   73 Jun  7 09:55 description
-rw-r--r-- 1 developer developer   23 Jun  7 09:55 HEAD
drwxr-xr-x 2 developer developer 4096 Jun  7 09:55 hooks
drwxr-xr-x 2 developer developer 4096 Jun  7 09:55 info
drwxr-xr-x 4 developer developer 4096 Jun  7 09:55 objects
drwxr-xr-x 4 developer developer 4096 Jun  7 09:55 refs
--endshelloutput

--newpage vim
--heading  blz, eu tenho meu código fonte aqui..

--beginoutput
$ vim index.html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Git - The Stupid Content Tracker</title>
</head>
<body>
   <a href="https://en.wikipedia.org/wiki/RTFM">RTFM</a>

   <label for="cpf">cpf</label>
   <input type="text">
</body>
</html>
--endoutput
---
--beginoutput
import Act from 'act';
import Previous from 'previous';


Act
    .find('cpf')
    .then(cpf => {
        Previous.validate(cpf);
    })
    .catch(e => console.log(e.message));
--endoutput

--newpage git status
--heading algo foi modificado?

--beginshelloutput
$ git status
On branch master

No commits yet

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        index.html
        app.js

nothing added to commit but untracked files present (use "git add" to track)
--endshelloutput

--newpage copy-paste
--heading tá, agora eu sei...

só copiar o demo para demo.20200608.zip, certo?
---
--beginslideleft
ééé.... não
--endslideleft
---

precisamos adicionar na 'staging area'
---

--beginshelloutput
$ git add index.html app.js
--endshelloutput
te lembra do git status?
---
--beginshelloutput
$ git status
On branch master

No commits yet

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)
        new file:   app.js
        new file:   index.html
--endshelloutput

--newpage commit
--heading e agora?

--beginshelloutput
$ git commit
--color green
Issue #01 Adiciona uns html/js ai.
--color white

adicionei um label, input e uma lib chamada Previous

nota:
   # Previous apresenta erros estranhos de build

--color cyan
 # Please enter the commit message for your changes. Lines starting
 # with '#' will be ignored, and an empty message aborts the commit.
 #
 # On branch master
 #
 # Initial commit
 #
 # Changes to be committed:
 #       new file:   app.js
 #       new file:   index.html
 #
--color white
--endshelloutput

--newpage log
--heading log

--beginshelloutput
$ git log
--color yellow
commit 182649b3492cf41251610ad7d332c6fb00ce9dac (HEAD -> master)
--color white
Author: Developer <developer@noprivacy.com>
Date:   Sun Jun 7 12:08:23 2020 -0300

    Issue #01 Adiciona uns html/js ai.

    adicionei um label, input e uma lib chamada Previous

    nota:
       # Previous apresenta erros estranhos de build
--endshelloutput

--newpage git diff
--heading o que mudou?
git diff

--newpage git rebase
--heading meu commit vai pro topo...
git rebase

--newpage git merge
--heading hora de unir forças...
git merge

--newpage url
--heading url suportadas

