<%--
  Created by IntelliJ IDEA.
  User: rinechran
  Date: 2020-09-25
  Time: 오전 3:47
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
    <jsp:useBean id="person" class="example.Person" scope="request"/>
    <jsp:setProperty name="person" property="id" value="201315"/>
    <jsp:setProperty name="person" property="name" value="정은식" />

    <p> 아이디 : <jsp:getProperty name="person" property="id"/>
    <p> 이름 : <jsp:getProperty name="person" property="name"/>
</body>
</html>
