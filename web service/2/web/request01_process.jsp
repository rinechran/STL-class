<%--
  Created by IntelliJ IDEA.
  User: rinechran
  Date: 2020-09-25
  Time: 오전 3:48
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
    <%
        request.setCharacterEncoding("UTF-8");
        String useid = request.getParameter("id");
        String password = request.getParameter("passwd");
    %>
    <p> 아이디 : <%= useid %> </p>
    <p> 비밀번호 : <%= password %> </p>
</body>
</html>
