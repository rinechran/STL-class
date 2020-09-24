<%--
  Created by IntelliJ IDEA.
  User: rinechran
  Date: 2020-09-25
  Time: 오전 3:45
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
    <jsp:useBean id="person" class="example.Person" scope="request"/>
    <p> 아이디 : <jsp:getProperty name="person" property="id"/>
    <p> 이름 : <jsp:getProperty name="person" property="name"/>
</body>
</html>
