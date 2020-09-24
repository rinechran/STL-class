<%--
  Created by IntelliJ IDEA.
  User: rinechran
  Date: 2020-09-25
  Time: 오전 2:56
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
    <p> 아이디 <%= request.getParameter("id") %>
        <%
            String name = request.getParameter("name");
        %>
    <p> 이름 : <%=java.net.URLDecoder.decode(name,"UTF-8")%>

</body>
</html>
