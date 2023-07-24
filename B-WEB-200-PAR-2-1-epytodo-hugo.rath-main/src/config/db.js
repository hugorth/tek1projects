const mysql = require('mysql2')

const {
    MYSQL_HOST,
    MYSQL_USER,
    MYSQL_ROOT_PASSWORD,
    MYSQL_DATABASE
} = process.env;

const connection = mysql.createConnection({
    host : MYSQL_HOST,
    user : MYSQL_USER,
    password : MYSQL_ROOT_PASSWORD,
    database : MYSQL_DATABASE
});

connection.connect((err) => {
    if (err) {
        console.error('erreur de connection a la base de donnees :', err);
        return;
    }
    console.log('connection reussie');
});

module.exports = connection;
