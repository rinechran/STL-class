<%--
  Created by IntelliJ IDEA.
  User: rinechran
  Date: 2020-09-25
  Time: 오전 3:44
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
    <jsp:useBean id="person" class="example.Person" scope="request"/>
    <jsp:setProperty name="person" property="id" value="2013150032"/>
    <jsp:setProperty name="person" property="name" value="정은식" />
    <p> 아이디 : <%= person.getId() %>
    <p> 이름 : <%= person.getName() %>
</body>
</html>
