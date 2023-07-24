const db = require('../../config/db');
const jwt = require('jsonwebtoken');

const all_user = (res, id) => {
  db.query('SELECT * FROM `user`', (err, results, fields) => {
    if (err) {
      console.error(err);
      res.status(500).json({ "msg": "internal server error" });
      return;
    }
    res.status(200).json(results);
  });
};

const all_todo = (res, id) => {
  db.query('SELECT * FROM todo WHERE user_id = ?', [id], (err, results, fields) => {
    if (err) {
      console.error(err);
      res.status(500).json({ "msg": "internal server error" });
      return;
    }
    res.status(200).json(results);
  });
};

const register = (res, mail, pwd, mname, fname) => {
  db.execute('INSERT INTO `user` (email, password, name, firstname) VALUES (?, ?, ?, ?)', [mail, pwd, mname, fname], (err, results, fields) => {
    if (err) {
      console.error(err);
      res.status(500).json({ "msg": "internal server error" });
      return;
    }
    const token = jwt.sign({ email: mail, password: pwd }, 'SECRET');
    res.status(200).json({ token });
  });
};

const check_account_mname = (res, mname, callback) => {
  db.execute('SELECT * FROM `user` WHERE name = ?', [mname], (err, results, fields) => {
    if (err) {
      console.error(err);
      res.status(500).json({ "msg": "internal server error" });
      return;
    }
    if (results.length > 0) {
      callback(84);
    } else {
      callback(0);
    }
  });
};

const check_account_mail = (res, mail, callback) => {
  db.execute('SELECT * FROM `user` WHERE email = ?', [mail], (err, results, fields) => {
    if (err) {
      console.error(err);
      res.status(500).json({ "msg": "internal server error" });
      return;
    }
    if (results.length > 0) {
      callback(84);
    } else {
      callback(0);
    }
  });
};

const get_mail_account = (res, mail, pwd, bcrypt, callback) => {
  db.execute('SELECT password, id FROM `user` WHERE email = ?', [mail], (err, results, fields) => {
    if (err) {
      console.error(err);
      res.status(500).json({ "msg": "internal server error" });
      return;
    }
    if (results.length > 0) {
      var pwd2 = results[0].password;
      var id2 = results[0].id;
      if (bcrypt.compareSync(pwd, pwd2)) {
        const token = jwt.sign({ email: mail, id: id2 }, 'SECRET');
        res.json({ token });
        callback(0);
      } else {
        callback(84);
      }
    } else {
      callback(84);
    }
  });
};

const get_info_id_or_mail = (res, data) => {
  db.execute('SELECT * FROM user WHERE email = ?', [data], (err, results, fields) => {
    if (err) {
      console.error(err);
      res.status(500).json({ "msg": "internal server error" });
      return;
    }
    if (results.length > 0) {
      res.status(200).json(results);
    } else {
      db.execute('SELECT * FROM user WHERE id = ?', [data], (err, results, fields) => {
        if (err) {
          console.error(err);
          res.status(500).json({ "msg": "internal server error" });
          return;
        }
        res.status(200).json(results);
      });
    }
  });
};

const delete_user_by_id = (res, id) => {
  db.execute('DELETE FROM `user` WHERE id = ?', [id], (err, results, fields) => {
    if (err) {
      console.error(err);
      res.status(500).json({ "msg": "internal server error" });
      return;
    }
    res.status(200).json({ "msg": `successfully deleted record number: ${id}` });
  });
};

const update_user_by_id = (res, id, email, pwd, mname, fname) => {
  db.execute('UPDATE `user` SET email = ?, password = ?, name = ?, firstname = ? WHERE id = ?', [email, pwd, mname, fname, id], (err, results, fields) => {
    if (err) {
      console.error(err);
      res.status(500).json({ "msg": "internal server error" });
      return;
    }
    db.execute('SELECT id, email, password, created_at, firstname, name FROM user WHERE id = ?', [id], (err, results, fields) => {
      if (err) {
        console.error(err);
        res.status(500).json({ "msg": "internal server error" });
        return;
      }
      res.status(200).json(results);
    });
  });
};

module.exports = {
  all_user,
  all_todo,
  register,
  check_account_mname,
  check_account_mail,
  get_mail_account,
  get_info_id_or_mail,
  delete_user_by_id,
  update_user_by_id
};
