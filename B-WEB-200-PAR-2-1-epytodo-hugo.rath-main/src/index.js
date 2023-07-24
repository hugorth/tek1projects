const express = require('express');
const app = express();
const bcrypt = require('bcryptjs');
const port = 3000;

app.use(express.urlencoded({ extended: true }));
app.use(express.json());
app.use(express.raw());

require('dotenv').config();

require('./routes/user/user.js')(app, bcrypt);
//require('./routes/todos/todos.js')(app, bcrypt);
require('./routes/auth/auth.js')(app, bcrypt);


app.listen(port, () => {
  console.log(`Example app listening at http://localhost:${port}`);
});
