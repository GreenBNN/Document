// require 요구한다 모듈을
var http = require('http');
var fs = require('fs');
var url = require('url');
var qs = require('querystring');
var template = require('./lib/template.js');
var path = require('path');
var sanitizeHtml = require('sanitize-html');

// nodejs 로 웹 브라우져가 접속이 들어올 때 마다 callback 함수를 호출한다
// 이때 두가지 인자가 전달된다.
// request 는 우리가 웹 브라우저에 담을 정보를 요청
// response 는 node가 요청에 대한 응답 정보
var app = http.createServer(function(request,response){
    // console.log(url); 전체 url parsing 가져오기
    var _url = request.url;
    // console.log(_url); id 값만 출력
    var queryData = url.parse(_url, true).query;
    var pathname = url.parse(_url, true).pathname;


    // id 를 가져와서 나중에 url 에 적용시켜 띄어야지
    //console.log(title);
    

    // 사용자가 접근할 때마다 위치와 url 을 출력
    // 읽어야할 파일을 가져와서 띄우는 형식
    // console.log(__dirname + url);
        
    //response.end(fs.readFileSync(__dirname + url));
    // console.log(url.parse(_url, true))
    // url을 따져 보니 id 앞 부분에 따라 사이트가 있는지 없는지 구분 가능함
    // 그걸 기준으로 나누어서 출력해주기
    if(pathname === '/'){
        if(queryData.id === undefined){
          fs.readdir('./data', function(error, filelist){
            var title = 'Welcome';
            var description = 'Hello, Node.js';
            var list = template.list(filelist);
            var html = template.HTML(title, list,
              `<h2>${title}</h2>${description}`,
              `<a href="/create">create</a>`
            );
            response.writeHead(200);
            response.end(html);
          });
        } else {
          fs.readdir('./data', function(error, filelist){
            var filteredId = path.parse(queryData.id).base;
            fs.readFile(`data/${filteredId}`, 'utf8', function(err, description){
              var title = queryData.id;
              var sanitizedTitle = sanitizeHtml(title);
              var sanitizedDescription = sanitizeHtml(description, {
                allowedTags:['h1']
              });
              var list = template.list(filelist);
              var html = template.HTML(sanitizedTitle, list,
                `<h2>${sanitizedTitle}</h2>${sanitizedDescription}`,
                ` <a href="/create">create</a>
                  <a href="/update?id=${sanitizedTitle}">update</a>
                  <form action="delete_process" method="post">
                    <input type="hidden" name="id" value="${sanitizedTitle}">
                    <input type="submit" value="delete">
                  </form>`
              );
              response.writeHead(200);
              response.end(html);
            });
          });
        }
    }
    else if(pathname === '/create'){
        fs.readdir('./data', function(error, filelist){
          var title = 'WEB - create';
          var list = template.list(filelist);
          var html = template.HTML(title, list, `
            <form action="/create_process" method="post">
              <p><input type="text" name="title" placeholder="title"></p>
              <p>
                <textarea name="description" placeholder="description"></textarea>
              </p>
              <p>
                <input type="submit">
              </p>
            </form>
          `, '');
          response.writeHead(200);
          response.end(html);
        });
    }
    else if(pathname === '/create_process'){
        var body = '';
        // data 가 너무 많으면 안좋으니 callback 으로 조각? 사이사이? 로 담음
        request.on('data', function (data){
            body += data;
        });
        // 정보를 다 받았으면 
        request.on('end', function(){
            var post = qs.parse(body);
            var title = post.title;
            var description = post.description;
            fs.writeFile(`data/${title}`, description, 'utf8', function(err){
              response.writeHead(302, {Location: `/?id=${title}`});
              response.end();
            })
        });
    } 
    else if(pathname === '/update'){
        fs.readdir('./data', function(error, filelist){
          var filteredId = path.parse(queryData.id).base;
          fs.readFile(`data/${filteredId}`, 'utf8', function(err, description){
            var title = queryData.id;
            var list = template.list(filelist);
            var html = template.HTML(title, list,
              `
              <form action="/update_process" method="post">
                <input type="hidden" name="id" value="${title}">
                <p><input type="text" name="title" placeholder="title" value="${title}"></p>
                <p>
                  <textarea name="description" placeholder="description">${description}</textarea>
                </p>
                <p>
                  <input type="submit">
                </p>
              </form>
              `,
              `<a href="/create">create</a> <a href="/update?id=${title}">update</a>`
            );
            response.writeHead(200);
            response.end(html);
          });
        });
    }
    else if(pathname === '/update_process'){
        var body = '';
        request.on('data', function(data){
            body = body + data;
        });
        request.on('end', function(){
            var post = qs.parse(body);
            var id = post.id;
            var title = post.title;
            var description = post.description;
            fs.rename(`data/${id}`, `data/${title}`, function(error){
              fs.writeFile(`data/${title}`, description, 'utf8', function(err){
                response.writeHead(302, {Location: `/?id=${title}`});
                response.end();
              })
            });
        });
      } else if(pathname === '/delete_process'){
        var body = '';
        request.on('data', function(data){
            body = body + data;
        });
        request.on('end', function(){
            var post = qs.parse(body);
            var id = post.id;
            var filteredId = path.parse(id).base;
            fs.unlink(`data/${filteredId}`, function(error){
              response.writeHead(302, {Location: `/`});
              response.end();
            })
        });
      } else {
        response.writeHead(404);
        response.end('Not found');
      }
});
app.listen(3000);