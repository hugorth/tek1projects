const db = require('../../config/db');

exports.all_todo = function(req, res) {
  db.query('SELECT * FROM `todo`', function(err, results, fields) {
    if (err) {
      console.error('Erreur lors de la récupération des tâches :', err);
      res.status(500).json({ "msg": "Erreur serveur" });
      return;
    }
    res.status(200).json(results);
  });
}

exports.todo_id = function(req, res) {
  const { id } = req.params;
  db.execute('SELECT * FROM `todo` WHERE id = ?', [id], function(err, results, fields) {
    if (err) {
      console.error('Erreur lors de la récupération de la tâche :', err);
      res.status(500).json({ "msg": "Erreur serveur" });
      return;
    }
    res.status(200).json(results);
  });
}

exports.create_todo = function(req, res) {
  const { title, description, due_time, user_id, status } = req.body;

  if (!title || !description || !due_time || !user_id || !status) {
    res.status(400).json({ "msg": "Paramètres manquants" });
    return;
  }

  db.execute('INSERT INTO `todo` (title, description, due_time, status, user_id) VALUES (?, ?, ?, ?, ?)', [title, description, due_time, status, user_id], function(err, results, fields) {
    if (err) {
      console.error('Erreur lors de la création de la tâche :', err);
      res.status(500).json({ "msg": "Erreur serveur" });
      return;
    }
    const id_task = results.insertId;
    db.execute('SELECT * FROM `todo` WHERE id = ?', [id_task], function(err, results, fields) {
      if (err) {
        console.error('Erreur lors de la récupération de la tâche créée :', err);
        res.status(500).json({ "msg": "Erreur serveur" });
        return;
      }
      res.status(200).json(results);
    });
  });
}

exports.delete_task_by_id = function(req, res) {
  const { id } = req.params;
  db.execute('DELETE FROM `todo` WHERE id = ?', [id], function(err, results, fields) {
    if (err) {
      console.error('Erreur lors de la suppression de la tâche :', err);
      res.status(500).json({ "msg": "Erreur serveur" });
      return;
    }
    res.status(200).json({ "msg": `Tâche supprimée avec succès : ${id}` });
  });
}

exports.update_task_by_id = function(req, res) {
  const { id } = req.params;
  const { title, description, due_time, user_id, status } = req.body;

  if (!title || !description || !due_time || !user_id || !status) {
    res.status(400).json({ "msg": "Paramètres manquants" });
    return;
  }

  db.execute('UPDATE `todo` SET title = ?, description = ?, due_time = ?, user_id = ?, status = ? WHERE id = ?', [title, description, due_time, user_id, status, id], function(err, results, fields) {
    if (err) {
      console.error('Erreur lors de la mise à jour de la tâche :', err);
      res.status(500).json({ "msg": "Erreur serveur" });
      return;
    }
    db.execute('SELECT id, title, description, created_at, due_time, user_id, status FROM todo WHERE id = ?', [id], function(err, results, fields) {
      if (err) {
        console.error('Erreur lors de la récupération de la tâche mise à jour :', err);
        res.status(500).json({ "msg": "Erreur serveur" });
        return;
      }
      res.status(200).json(results);
    });
  });
}
