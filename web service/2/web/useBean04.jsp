<%--
  Created by IntelliJ IDEA.
  User: rinechran
  Date: 2020-09-25
  Time: 오전 3:39
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
    <jsp:useBean id="person" class="example.Person"  scope="request"/>
    <p> 아이디 : <%= person.getId() %>
    <p> 이름 : <%= person.getName() %>
    <%
            person.setId("2013150032");
            person.setName("정은식");
    %>
    <jsp:include page="useBean03.jsp"/>
</body>
</html>
