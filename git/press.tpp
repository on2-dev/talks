--author 404
--title git - the stupid content tracker
--date today

--newpage intro
--heading o que é esse tal de git ?

* gerenciador de versões
* criado em 2005 para substituir BitKeeper
* trabalha com snapshots
* historico local

--newpage init
--heading iniciando um repositório...

---
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

--center urls suportadas:
---
*   ssh://[user@]host.xz[:port]/path/to/repo.git/
---
*   git://host.xz[:port]/path/to/repo.git/
---
*   http[s]://host.xz[:port]/path/to/repo.git/
---
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

--beginshelloutput
$ vim index.html
--endshelloutput
---

--beginoutput
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
: ajuiekdkLKskj
--endoutput

--newpage git status
--heading algo foi modificado?

--beginshelloutput
$ git status
On branch master

No commits yet

--color red
Untracked files:
--color white
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
ééé....   
--endslideleft
--sleep 1
não
---

precisamos informar ao git para versionar o arquivo
---

--beginshelloutput
$ git add index.html app.js
--endshelloutput

---
te lembra do git status?
---
--beginshelloutput
$ git status

On branch master

No commits yet

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)
--color green
        new file:   app.js
        new file:   index.html
--color white
--endshelloutput

--newpage git commit
--heading e agora?

--beginshelloutput
$ git commit
--endshelloutput

--sleep 1
--beginoutput
--color green
Issue #01 Adiciona uns html/js ai.
--color white

adicionei um label, input e uma lib chamada Previous

nota:
   - Previous apresenta erros estranhos de build

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
--endoutput
---
--beginoutput
$ git config core.editor vim | nano | vscodium | subl | code
--endoutput

--newpage git log
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


--newpage git show
--heading 
--beginshelloutput
$ git show --stat 182649b3492cf41251610ad7d332c6fb00ce9dac

--color yellow
commit 182649b3492cf41251610ad7d332c6fb00ce9dac
--color white
Author: developer <developer@noprivacy.com>
Date:   Sun Jun 7 12:08:23 2020 -0300

    Issue #01 Adiciona uns html/js ai.

    adicionei um label, input e uma lib chamada Previous

    nota:
       # Previous apresenta erros estranhos de build

 app.js     |  9 +++++++++
 index.html | 13 +++++++++++++
 2 files changed, 22 insertions(+)
--endshelloutput

--newpage git blame
--heading achando o culpado...

--beginshelloutput
$ git blame index.html

^182649b (developer 2020-06-07 12:08:23 -0300  1) <!DOCTYPE html>
^182649b (developer 2020-06-07 12:08:23 -0300  2) <html lang="en">
^182649b (developer 2020-06-07 12:08:23 -0300  3) <head>
^182649b (developer 2020-06-07 12:08:23 -0300  4)     <meta charset="UTF-8">
^182649b (developer 2020-06-07 12:08:23 -0300  5)     <title>Git - The Stupid Content Tracker</title>
^182649b (developer 2020-06-07 12:08:23 -0300  6) </head>
^182649b (developer 2020-06-07 12:08:23 -0300  7) <body>
^182649b (developer 2020-06-07 12:08:23 -0300  8)    <a href="https://en.wikipedia.org/wiki/RTFM">RTFM</a>
^182649b (developer 2020-06-07 12:08:23 -0300  9) 
b8ae6687 (developer 2020-06-07 14:11:07 -0300 10)    <form class="form">
66a821d0 (developer 2020-06-07 14:05:26 -0300 11)       <fieldset>
66a821d0 (developer 2020-06-07 14:05:26 -0300 12)          <legend>Digite o cpf</legend>
b8ae6687 (developer 2020-06-07 14:11:07 -0300 13)       <div class="form-group">
b8ae6687 (developer 2020-06-07 14:11:07 -0300 14)       <label for="cpf">cpf</label>
b8ae6687 (developer 2020-06-07 14:11:07 -0300 15)       <input type="text">
b8ae6687 (developer 2020-06-07 14:11:07 -0300 16)       </div>
d6070543 (developer 2020-06-07 12:31:14 -0300 17) 
d6070543 (developer 2020-06-07 12:31:14 -0300 18) 
b8ae6687 (developer 2020-06-07 14:11:07 -0300 19)       <button type="submit" class="btn btn-primary">Validar</button>
66a821d0 (developer 2020-06-07 14:05:26 -0300 20)       </fieldset>
d6070543 (developer 2020-06-07 12:31:14 -0300 21)    </form>
^182649b (developer 2020-06-07 12:08:23 -0300 22) </body>
^182649b (developer 2020-06-07 12:08:23 -0300 23) </html>
--endshelloutput

--newpage git diff
--heading o que mudou?

--beginshelloutput
$ git diff

 diff --git a/index.html b/index.html
 index 62722d7..cc14182 100644
 --- a/index.html
 +++ b/index.html
 @@ -7,7 +7,12 @@
  <body>
     <a href="https://en.wikipedia.org/wiki/RTFM">RTFM</a>
--color red
 -   <label for="cpf">cpf</label>
 -   <input type="text">
--color green
 +   <form>
 +      <label for="cpf">cpf</label>
 +      <input type="text">
 +
 +
 +      <input type="button" value="Validar">
 +   </form>
--color white
 </body>
 </html>
--endshelloutput
---

--beginshelloutput
$ git commit -m "fix form tag"

[master d607054] fix form tag
 1 file changed, 7 insertions(+), 2 deletions(-)
--endshelloutput

--newpage git remote
--heading git remoto

--beginshelloutput
$ git remote add origin git@githome.com:developer/demo.git
--endshelloutput

--beginshelloutput
$ git remote

 origin
--endshelloutput

---

--beginshelloutput
$ git push -u origin master
--endshelloutput

---
--beginshelloutput
$ git status
On branch master
Your branch is up to date with 'origin/master'.

nothing to commit, working tree clean
--endshelloutput

--newpage git branch
--heading trabalhando com branches

--beginshelloutput
$ git branch --show-current

 master
--endshelloutput
---
--beginshelloutput
$ git branch -a

--color green
 * master
--color red
  remotes/origin/master
--color white
--endshelloutput

--newpage git branch
--heading trabalhando com branches
--beginshelloutput
$ git branch bootstrap  # branch atual como base
--endshelloutput
---

--beginshelloutput
$ git branch bootstrap master # branch ou hash como referência
--endshelloutput

---
--beginshelloutput
$ git checkout bootstrap # troca para o branch criado
--endshelloutput
---

--beginshelloutput
$ git branch
 bootstrap
--endshelloutput
---
--beginshelloutput
$ git branch --delete bootstrap
---
$ git branch -d bootstrap
--endshelloutput

--newpage git diff
--heading comparando arquivos
--beginshelloutput
$ git diff master bootstrap index.html

 diff --git a/index.html b/index.html
 index e7fea2c..999d1e3 100644
 --- a/index.html
 +++ b/index.html
 @@ -7,15 +7,14 @@
  <body>
     <a href="https://en.wikipedia.org/wiki/RTFM">RTFM</a>
--color red 
 -   <form>
 -      <fieldset>
 -         <legend>Digite o cpf</legend>
 -         <label for="cpf">cpf</label>
 -         <input type="text">
--color green
 +   <form class="form">
 +      <div class="form-group">
 +      <label for="cpf">cpf</label>
 +      <input type="text">
 +      </div>
  
--color red 
 -         <input type="button" value="Validar">
 -      </fieldset>
--color green
 +      <button type="submit" class="btn btn-primary">Validar</button>
--color white
     </form>
  </body>
  </html>
--endshelloutput

--newpage git rebase
--heading meu commit vai pro topo...
--beginshelloutput
$ git rebase master

Auto-merging index.html
--color cyan
CONFLICT (content): Merge conflict in index.html
--color white
error: could not apply de5aa34... add some boostrap class
Resolve all conflicts manually, mark them as resolved with
---
--color green
"git add/rm <conflicted_files>", then run "git rebase --continue".
---
You can instead skip this commit: run "git rebase --skip".
---
To abort and get back to the state before "git rebase", run "git rebase --abort".
--color white
Could not apply de5aa34... add some boostrap class
--endshelloutput

--newpage git rebase
--heading meu commit vai pro topo...
--beginshelloutput
$ git status
--color red
interactive rebase in progress; onto 9e10be4
--color white
Last command done (1 command done):
   pick de5aa34 add some boostrap class
No commands remaining.
You are currently rebasing branch 'bootstrap' on '9e10be4'.
  (fix conflicts and then run "git rebase --continue")
  (use "git rebase --skip" to skip this patch)
  (use "git rebase --abort" to check out the original branch)

Unmerged paths:
  (use "git restore --staged <file>..." to unstage)
  (use "git add <file>..." to mark resolution)
--color red
        both modified:   index.html
--color white

no changes added to commit (use "git add" and/or "git commit -a")
--endshelloutput

--newpage git rebase
--heading deu peleia...

--beginshelloutput
$ vim index.html
--endshelloutput

--beginoutput
...
--color cyan
<<<<<<< HEAD
   <form>
      <fieldset>
         <legend>Digite o cpf</legend>
         <label for="cpf">cpf</label>
         <input type="text">


         <input type="button" value="Validar">
      </fieldset>
--color red
=======
   <form class="form">
      <div class="form-group">
      <label for="cpf">cpf</label>
      <input type="text">
      </div>


      <button type="submit" class="btn btn-primary">Validar</button>
>>>>>>> de5aa34... add some boostrap class
--color white
...
--endoutput



--newpage git rebase
--heading não estavam pra peleia, só atiravam pra errar...

--beginoutput
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Git - The Stupid Content Tracker</title>
</head>
<body>
   <a href="https://en.wikipedia.org/wiki/RTFM">RTFM</a>

   <form class="form">
--color cyan
      <fieldset>
        <legend>Digite o cpf</legend>
--color white
        <div class="form-group">
        <label for="cpf">cpf</label>
        <input type="text">
        </div>


        <button type="submit" class="btn btn-primary">Validar</button>
--color cyan
      </fieldset>
--color white
   </form>
</body>
</html>
--endoutput

--newpage after conflict
--heading depois da peleia..




--beginshelloutput
$ git add index.html
--endshelloutput
---




--beginshelloutput
$ git rebase --continue
--endshelloutput


--newpage git merge
--heading hora de unir forças...


--beginshelloutput
$ git checkout master
--endshelloutput

---

--beginshelloutput
$ git merge --no-ff boostrap
--endshelloutput

--newpage git merge
--heading hora de unir forças...

--beginshelloutput
$ git log --graph

--color yellow 
*   commit 762f922054d93faa07cea3c06f54f6a595171ab7 (HEAD -> master)
--color white
|\  Merge: 9e10be4 b8ae668
| | Author: developer <developer@noprivacy.com>
| | Date:   Sun Jun 7 15:18:56 2020 -0300
| |
| |     Merge branch 'bootstrap'
| |
--color yellow 
| * commit b8ae6687ee304a141b9f59590e216cfdac31831e (bootstrap)
--color white
|/  Author: developer <developer@noprivacy.com>
|   Date:   Sun Jun 7 14:11:07 2020 -0300
|
|       add some boostrap class
|
*   commit 9e10be43abef0d9e10b3d4d7ac7bb6b4fb1f74c2
...
--endshelloutput

--newpage mice
--heading eu gosto de mouse

       ____()()
      /      @@
`~~~~~\_;m__m._>o    jgs

--center            _    _             _     
--center         _ ( )_ ( )           ( )    
--center    __  (_)| ,_)| |__   _   _ | |_   
--center  /'_ `\| || |  |  _ `\( ) ( )| '_`\ 
--center ( (_) || || |_ | | | || (_) || |_) )
--center `\__  |(_)`\__)(_) (_)`\___/'(_,__/'
--center ( )_) |                             
--center  \___/'                             
--right  _         _    _                    _             _   
--right ( )     _ ( )_ ( )                  ( )           ( )_ 
--right | |_   (_)| ,_)| |_    _   _    ___ | |/')    __  | ,_)
--right | '_`\ | || |  | '_`\ ( ) ( ) /'___)| , <   /'__`\| |  
--right | |_) )| || |_ | |_) )| (_) |( (___ | |\`\ (  ___/| |_ 
--right (_,__/'(_)`\__)(_,__/'`\___/'`\____)(_) (_)`\____)`\__)
           _    _           _     
        _ ( )_ (_ )        ( )    
   __  (_)| ,_) | |    _ _ | |_   
 /'_ `\| || |   | |  /'_` )| '_`\ 
( (_) || || |_  | | ( (_| || |_) )
`\__  |(_)`\__)(___)`\__,_)(_,__/'
( )_) |                           
 \___/'                           

--newpage references
--heading Referências

--beginshelloutput
$ man git
$ man git commit
$ man git log
$ man git diff
$ man git remote
$ man git branch
$ man git rebase
$ man git merge
--endshelloutput

 https://git-scm.com/
 https://www.asciiart.eu/animals/rodents/mice
